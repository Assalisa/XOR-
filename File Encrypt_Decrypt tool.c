#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void encrypt_decrpt(char *input_filename,char *output_filename,char *key)
{
	FILE *input_file=fopen(input_filename,"rb");
	if(input_file==NULL)
	{
		perror("error opening input file"); 
		exit(EXIT_FAILURE);
	}
	FILE *output_file=fopen(output_filename,"wb"); 
	if(output_file==NULL)
	{
		perror("error opening output file"); 
		exit(EXIT_FAILURE);
	}
	int key_length=strlen(key);
	int key_index=0;
	int byte;
	while((byte=fgetc(input_file))!=EOF)
	{
		fputc(byte ^ key[key_index],output_file);
		key_index=(key_index+1)%key_length;
	}
	fclose(input_file);
	fclose(output_file);	
}
int main()
{
	char input_filename[256];
	char output_filename[256];
	char key[256];
	int choice;
	while(1)
	{
		printf("File Encrypt_Decrypt tool\n");
		printf("Input number to start\n");
		printf("1-Encrypt\n");
		printf("2-Decrypt\n");
		printf("3-Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Please input Encrypt filename");
			scanf("%s",input_filename);
			printf("pLease input Encrypt filename");
			scanf("%s",output_filename);
			printf("Input Encrypt key:");
			scanf("%s",key);
			encrypt_decrpt(input_filename,output_filename,key);
			printf("Encrypt success \n");
			break;
		case 2:
		 	printf("Please input Decrypt filename");
			scanf("%s",input_filename);
			printf("Please input Decrypted filename");
			scanf("%s",output_filename);
			printf("Please inpute key:");
			scanf("%s",key);
			encrypt_decrpt(input_filename,output_filename,key);
			printf("Decrypt success\n");
			break;
		case 3:
			exit(EXIT_SUCCESS);
		default:
			printf("Error input\n"); 		
		}	
	}
	return 0;
}