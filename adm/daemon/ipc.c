#include <std.h>
#include <socket_err.h>
#include <daemons.h>

#pragma strict_types
#pragma warnings

#define SOCK_MODE 1
#define IPC_PORT 8181

inherit DAEMON;

int *ttys = ({});
int conn_fd;

void debug(string s)
{
    log_file("ipc", s);
    return;
}

int create()
{
    ipc_setup_socket();

    return 1;
}

void ipc_setup_socket()
{
    int conn_stat;

    conn_fd = socket_create(SOCK_MODE,"ipc_read", "ipc_shutdown");

    if (conn_fd < 0) {
        debug("Error create");
        return;
    }

    conn_stat = socket_bind(conn_fd, 8181);

    if (conn_stat < 0) {
        debug("Error bind");
        return;
    }

    conn_stat = socket_listen(conn_fd, "ipc_listen");

    if (conn_stat < 0) {
        debug("Error listen");
        return;
    }

    debug("Ok listen");
}

void ipc_listen(int fd)
{
    int this_conn_fd;

    this_conn_fd = socket_accept(fd, "ipc_read", "ipc_write");

    if (this_conn_fd < 0) {
        debug("Error listen");
        return;
    }

    ttys += ({this_conn_fd});
}

/**
 * This function reads for IPC messages.
 *
 * As we can't bind to interfaces from LPC it is advised you either
 * implement auth, or deny connections in net filter.
 *
 * @param fd Socket's file descriptor.
 * @param data Recieved data,
 */
void ipc_read(int fd, mixed data)
{

    if (!stringp(data))
    {
        socket_close(fd);
        debug("Error non string");
        return;
    }

    if (!regexp(socket_address(fd), "^127.0.0.1")) {
        socket_close(fd);
        debug("Error non local");
        return;
    }

    if (sizeof(data) > 1024) {
        debug("Error size");
        return;
    }

    // Messages handling here.

    if (regexp(data, "^CHAT:")) {
        string chan, pos, nick, msg;

        debug(identify(data));

        if (sscanf(data, "CHAT:%s:%s:%s:%s", chan, pos, nick, msg) != 4) {
            debug("Malformed chat msg");
            return;
        }


        CHAT_D->ipc_chat(chan, nick, msg);
    }


}

int *query_ttys()
{
    return ttys;
}

int *ipc_send_all(mixed data)
{
    int tty;

    foreach(tty in ttys)
    {
        socket_write(tty, data);
    }
}

int ipc_close_all()
{
    int tty;

    foreach(tty in ttys) {
        socket_close(tty);
    }

    return;
}

void ipc_shutdown(int fd)
{
    ttys -= ({fd});
    return;
}
