#include <my_global.h>
#include <mysql.h>

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
	printf("show data product\r\n");
	if (mysql_query(con, "SELECT * FROM product"))
	{
		printf("error: %s\r\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	MYSQL_RES *result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("error: %s\r\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	int i;
	while ((row = mysql_fetch_row(result)))
	{
	  for(i = 0; i < num_fields; i++)
	  {
		  printf("%s\t", row[i] ? row[i] : "NULL");
	  }
	  printf("\r\n");
	}

	mysql_free_result(result);

	printf("closing connection...\r\n");

	mysql_close(con);
	printf("closed.\r\n");

	exit(0);
}
