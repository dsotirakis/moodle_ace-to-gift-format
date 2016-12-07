#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	/*initialize your input file (questions file) and your output file (gift-formatted)*/
    FILE* file_in = fopen("/home/dimitris/Desktop/program.txt", "r"); /* should check the result */
    FILE* file_out = fopen("/home/dimitris/Desktop/output.txt", "w");
    char line[6500][1000];
    int count=0;
    char cmp;
    int flag, i=1, start, i_init=0, flag1=0;

    /* read each of the lines in the file and repeat until EOF*/ 
    while (fgets(line[count], sizeof(line[count]), file_in)) {
    	flag=0;

    	/* check if the first character of the string is a number -> it refers to a question*/
    	if (isdigit(line[count][0])) {
    		size_t ln = strlen(line[count])-1;
			if (line[count][ln] == '\n') line[count][ln] = '\0';
			if (flag1==1){
    			fprintf(file_out, "}");
    			fprintf(file_out, "\n\n");
    		}
    		flag1=1;
    		start=0;
    		i=count+1;
    		fprintf(file_out, "::%s{\n", line[count]);
	        count++;
    		continue;
    	}
    	start++;
    	if (start==6) {
    		i_init=i;
    		strcpy(&cmp, &line[count][0]);
    		while (flag==0){
    			if (cmp==line[i][0]){
    				line[i][0]='=';
    				line[i][1]=' ';
    				fprintf(file_out, "%s", line[i]);
    				line[count][0]='#';
    				line[count][1]=' ';
    				fprintf(file_out, "%s", line[count]);
    			}
    			else{
    				line[i][0]='~';
    				line[i][1]=' ';
    				fprintf(file_out, "%s", line[i]);
    			}
    			i++;
    			if((i-i_init)==4) flag=1;
    		}
    		i=count-6;
    		while (i<5+count){
    			i++;
    		}
    	}
        count++;
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
    printf("Convertion done!\n");
    fprintf(file_out, "}");
    fclose(file_in);
    fclose(file_out);

    return 0;
}