#include <my_global.h>
#include <mysql.h>
#include <string.h>

#define DELETE_DATA "delete from product where idproduct=?"

int main(int argc, char **argv)
{

	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
	  fprintf(stderr, "%s\n", mysql_error(con));
	  exit(1);
	}
	printf("connecting to mysql server...\r\n");
	// change host, username, and password
	if (mysql_real_connect(con, "localhost", "root", "password",
		  "mydatabase", 0, NULL, 0) == NULL)
	{
		printf("error: %s\r\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	printf("connected.\r\n");
	printf("inserting 10 data...\r\n");

	MYSQL_STMT  *stmt;

	stmt = mysql_stmt_init(con);
	if (!stmt)
	{
		printf(" mysql_stmt_init(), out of memory\r\n");
		exit(0);
	}

	if (mysql_stmt_prepare(stmt, DELETE_DATA, strlen(DELETE_DATA)))
	{
		printf("mysql_stmt_prepare(), UPDATE failed\r\n");
		printf("error: %s\r\n", mysql_stmt_error(stmt));
		exit(0);
	}

	int i;
	MYSQL_BIND  bind[1];
	int product_id;

	memset(bind, 0, sizeof(bind));

	bind[0].buffer_type= MYSQL_TYPE_LONG;
	bind[0].buffer= (char *)&product_id;
	bind[0].is_null= 0;
	bind[0].length= 0;

	// bind parameters
	if (mysql_stmt_bind_param(stmt, bind))
	{
		printf("mysql_stmt_bind_param() failed\r\n");
		printf("%s\r\n", mysql_stmt_error(stmt));
		exit(0);
	}

	// select product id to be deleted
	// change these values!!
	product_id = 28;

	printf("deleting data...\r\n");
	if (mysql_stmt_execute(stmt))
	{
		printf("mysql_stmt_execute(), 1 failed\r\n");
		printf("%s\r\n", mysql_stmt_error(stmt));
		exit(0);
	}
	printf("done.\r\n");
	printf("closing connection...\r\n");

	/* Close the statement */
	if (mysql_stmt_close(stmt))
	{
		printf("failed while closing the statement\r\n");
		printf("%s\r\n", mysql_stmt_error(stmt));
		exit(0);
	}
	mysql_close(con);
	printf("closed.\r\n");

	exit(0);
}
