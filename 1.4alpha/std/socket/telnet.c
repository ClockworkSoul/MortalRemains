// written by Dwayne Fontenot (Jacques)
// last modified: 1992 October 19 (runs on the Basis mudlib)

// This object implements a telnet client (providing a subset of the telnet
// protocol) using STREAM mode of MudOS 0.9 LPC sockets.  See the init()
// function // to find out the commands this terminal understands.
// This object may be used from within a MudOS mud to connect to any
// networked server that understands the telnet protocol (including
// another LPmud).

#include <config.h>
#include <net/socket.h>
#include <driver/origin.h>

#define WRITE_WAIT_CALLBACK 0
#define WRITE_GO_AHEAD      1

#define STD_TELNET 23

#define IAC  255
#define DONT 254
#define DO   253
#define WONT 252
#define WILL 251

#define TELOPT_ECHO   1
#define TELOPT_SGA    3
#define TELOPT_TTYPE 24
#define TELOPT_NAWS  31

static string *telopts = ({"BINARY", "ECHO", "RCP", "SUPPRESS GO AHEAD",
			"NAME", "STATUS", "TIMING MARK", "RCTE", "NAOL", "NAOP",
		    "NAOCRD", "NAOHTS", "NAOHTD", "NAOFFD", "NAOVTS",
		    "NAOVTD", "NAOLFD", "EXTEND ASCII", "LOGOUT", "BYTE MACRO",
		    "DATA ENTRY TERMINAL", "SUPDUP", "SUPDUP OUTPUT",
		    "SEND LOCATION", "TERMINAL TYPE", "END OF RECORD",
		    "TACACS UID", "OUTPUT MARKING", "TTYLOC",
		    "3270 REGIME", "X.3 PAD", "NAWS", "TSPEED", "LFLOW",
		    "LINEMODE"});

static string s_iac_dont_echo;
static string s_iac_do_echo;
static string s_iac_wont_echo;
static string s_iac_will_echo;
static string s_iac_dont_sga;
static string s_iac_do_sga;
static string s_iac_wont_sga;
static string s_iac_will_sga;
static string s_iac_wont_ttype;
static string s_iac_wont_naws;
static string s_iac;
static string s_dont_echo;
static string s_do_echo;

private string callback;

private int conn_fd;
private string conn_host;
private int conn_port;
private int connected;
private int verbose;

private int write_state = WRITE_WAIT_CALLBACK;
private string write_message = "";

static void init_tel_neg()
{
  s_iac_dont_echo  = sprintf("%c%c%c",IAC,DONT,TELOPT_ECHO);
  s_iac_do_echo    = sprintf("%c%c%c",IAC,DO  ,TELOPT_ECHO);
  s_iac_wont_echo  = sprintf("%c%c%c",IAC,WONT,TELOPT_ECHO);
  s_iac_will_echo  = sprintf("%c%c%c",IAC,WILL,TELOPT_ECHO);
  s_iac_dont_sga   = sprintf("%c%c%c",IAC,DONT,TELOPT_SGA);
  s_iac_do_sga     = sprintf("%c%c%c",IAC,DO  ,TELOPT_SGA);
  s_iac_wont_sga   = sprintf("%c%c%c",IAC,WONT,TELOPT_SGA);
  s_iac_will_sga   = sprintf("%c%c%c",IAC,WILL,TELOPT_SGA);
  s_iac_wont_ttype = sprintf("%c%c%c",IAC,WONT,TELOPT_TTYPE);
  s_iac_wont_naws  = sprintf("%c%c%c",IAC,WONT,TELOPT_NAWS);
  s_iac            = sprintf("%c",    IAC);
  s_dont_echo      = sprintf("%c%c",  DONT,TELOPT_ECHO);
  s_do_echo        = sprintf("%c%c",  DO,  TELOPT_ECHO);
}

void
set_callback(string arg)
{
	callback = arg;
}

void create()
{
  init_tel_neg();
  connected = 0;
  verbose = 0;
  set_callback("handler");
}

void
set_verbosity(int v)
{
	verbose = v;
}

int
query_connected()
{
	return connected;
}

void disconnected()
{
  call_other(this_object(), callback, "close");
  connected = 0;
}

int connected()
{
  call_other(this_object(), callback, "open");
  connected++;
}

void my_socket_write(int fd, string message)
{
  int ret;

  write_message = write_message + message;
  if(write_state == WRITE_GO_AHEAD){
    ret = socket_write(fd, write_message);
    write_message = "";
    if(ret == EESUCCESS) write_state = WRITE_GO_AHEAD;
    else if(ret == EECALLBACK) write_state = WRITE_WAIT_CALLBACK;
    else if(ret == EEWOULDBLOCK || ret == EEALREADY)
      call_out("my_socket_write", 10, fd, "");
  }
}

int line(string str)
{
  if(connected == 2){
    my_socket_write(conn_fd,s_iac_dont_sga+s_iac_dont_echo);
    write("SENT dont SUPPRESS GO AHEAD\nSENT dont ECHO\n");
    return(1);
  }
  return(0);
}

int char(string str)
{
  if(connected == 2){
    my_socket_write(conn_fd,s_iac_do_sga+s_iac_do_echo);
    write("SENT do SUPPRESS GO AHEAD\nSENT do ECHO\n");
    return(1);
  }
  return(0);
}

int connect(string str)
{
  int ret;

  if(!str) return(0);
  if (connected == 2){
    notify_fail("Already connected to " + socket_address(conn_fd) + ".\n");
    return(0);
  } else if (connected == 1){
    notify_fail("Connection in progress.\n");
    return(0);
  }

  conn_fd = socket_create(STREAM,"socket_shutdown");
  if (sscanf(str, "%s %d", conn_host, conn_port) != 2) {
    conn_host = str;
    conn_port = STD_TELNET;
  }
  connected();
  resolve(conn_host, "resolve_connect");
  return(1);
}

int send(string str)
{
  if(connected==2){
    if(!str){
      write("Sending CR.\n");
      my_socket_write(conn_fd,"\n");
      return(1);
    }
    my_socket_write(conn_fd,str + "\n");
    return(1);
  }
  return(0);
}

int disconnect(string str)
{
  int ret;

  if (!connected){
    notify_fail("Not connected anywhere.\n");
    return(0);
  }
  ret = socket_close(conn_fd);
  conn_fd = -1;
  disconnected();
  if(ret < 0){
    notify_fail("unable to disconnect cleanly.\n");
    return(0);
  }
  return(1);
}

void receive_data(int rec_fd,string msg)
{
  string *chunks;
  int i;
  object hearer;

  hearer = environment(this_object());
  chunks = explode(msg,s_iac);
  for(i=0;i<sizeof(chunks);i++){
    switch(chunks[i][0]){
    case DONT:
      if (verbose)
          message("telnet","RCVD dont "+telopts[chunks[i][1]]+"\n",hearer,
	      this_object());
      switch(chunks[i][1]){
      case TELOPT_ECHO:
	message("telnet_neg",s_iac_dont_echo,hearer,this_object());
	break;
      }
      if(strlen(chunks[i]) > 2)
	message("telnet",chunks[i][2..strlen(chunks[i])-1],hearer,
		this_object());
      break;
    case DO:
      if (verbose)
         message("telnet","RCVD do "+telopts[chunks[i][1]]+"\n",hearer,
	      this_object());
      switch(chunks[i][1]){
      case TELOPT_ECHO:
	my_socket_write(rec_fd,s_iac_wont_echo);
    if (verbose)
	   message("telnet","SENT wont ECHO\n",hearer,this_object());
	break;
      case TELOPT_TTYPE:
	my_socket_write(rec_fd,s_iac_wont_ttype);
    if (verbose)
    	message("telnet","SENT wont TERMINAL TYPE\n",hearer,this_object());
	break;
      case TELOPT_NAWS:
	my_socket_write(rec_fd,s_iac_wont_naws);
	    if (verbose)
        message("telnet","SENT wont NAWS\n",hearer,this_object());
	break;
      default:
    my_socket_write(rec_fd,sprintf("%c%c%c",IAC,WONT,TELOPT_ECHO));
	if (verbose)
	message("telnet","SENT wont " + chunks[i][1] + "\n",hearer,
		this_object());
	break;
      }
      if(strlen(chunks[i]) > 2)
	message("telnet",chunks[i][2..strlen(chunks[i])-1],hearer,
		this_object());
      break;
    case WONT:
	  if (verbose)
      message("telnet","RCVD wont "+telopts[chunks[i][1]]+"\n",hearer,
	      this_object());
      switch(chunks[i][1]){
      case TELOPT_ECHO:
	message("telnet_neg",s_iac_wont_echo,hearer,this_object());
	break;
      case TELOPT_SGA:
	message("telnet_neg",s_iac_wont_sga,hearer,this_object());
        break;
      }
      if(strlen(chunks[i]) > 2)
	message("telnet",chunks[i][2..strlen(chunks[i])-1],hearer,
		this_object());
      break;
    case WILL:
	  if (verbose)
      message("telnet","RCVD will "+telopts[chunks[i][1]]+"\n",hearer,
	      this_object());
      switch(chunks[i][1]){
      case TELOPT_ECHO:
	message("telnet_neg",s_iac_will_echo,hearer,this_object());
	my_socket_write(rec_fd,s_iac_do_echo);
	if (verbose)
	message("telnet","SENT do ECHO\n",hearer,this_object());
	break;
      case TELOPT_SGA:
        message("telnet_neg",s_iac_will_sga,hearer,this_object());
	break;
      }
      if(strlen(chunks[i]) > 2)
	message("telnet",chunks[i][2..strlen(chunks[i])-1],hearer,
		this_object());
      break;
    default:
      message("telnet",chunks[i],hearer,this_object());
      break;
    }
  }
}

void write_data(int fd)
{
  write_state = WRITE_GO_AHEAD;
  my_socket_write(fd,"");
}

varargs void socket_shutdown(int fd)
{
  object hearer;

  if ((origin() == ORIGIN_LOCAL || origin() == ORIGIN_DRIVER) ||
        fd == conn_fd) {
    hearer = environment(this_object());
    socket_close(fd);
    conn_fd = -1;
    disconnected();
    return;
  }
}

void resolve_connect( string name, string number, int key ) {
    int ret;

    if (connected) {
      if (number)
        conn_host = number;
      ret = socket_connect(conn_fd, sprintf("%s %d", conn_host, conn_port),
          "receive_data", "write_data");
      if(ret == EESUCCESS) {
        connected();
        return;
      }
    }
    if (interactive(environment())) {
      message("error","unable to connect: " + socket_error(ret) + "\n",
          environment());
      disconnect(0);
    }
}