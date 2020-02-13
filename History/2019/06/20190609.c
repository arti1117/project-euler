/*
 * 20190609.c
 *
 *  Created on: Jun 9, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <string.h>

void test()
{
	char cmd[100];  // to hold the command.
	char to[] = "sample@example.com"; // email id of the recepient.
	char body[] = "SO rocks";    // email body.
	char tempFile[100];     // name of tempfile.

	strcpy(tempFile,tempnam("/tmp","sendmail")); // generate temp file name.

	FILE *fp = fopen(tempFile,"w"); // open it for writing.
	fprintf(fp,"%s\n",body);        // write body to it.
	fclose(fp);             // close it.

	sprintf(cmd,"sendmail %s < %s",to,tempFile); // prepare command.
	system(cmd);     // execute it.
}
