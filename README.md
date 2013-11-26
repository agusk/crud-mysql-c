## CRUD-MySQL-C
C code ilustration for CRUD (Create, Read, Update, Delete) with MySQL database.

## System Requirements

Linux platform with installed gcc. You also need MySQL for database testing. For Debian/Ubuntu, you can install mysql-server and mysql-client.

	$ sudo apt-get install mysql-server mysql-client

You also need MySQL Development library, libmysqlclient-dev.

	$ sudo apt-get install libmysqlclient-dev

## Database

For database testing, you can run database.sql script to execute database and table.

## Compiling & Linking

Before compiling, please change database configured based on your MySQL configuration. To build demo-create-data.c, you do the following command. 

	$ gcc -c -I/usr/include/mysql demo-create-data.c 
	$ gcc -o demo-create-data demo-create-data.o -L/usr/lib/mysql -lmysqlclient


## License

The MIT License (MIT)

Copyright (c) 2013 Agus Kurniawan

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
