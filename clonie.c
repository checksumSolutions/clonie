#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void clearBuf(){
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

int dirtyClone(){
	char sdrive[25];
	char tdrive[25];
	char command[100];
	char choice;
	int bsInt = 512;
	char *c;

	system("clear");
	printf("Dirty clone: \n\n");
	system("lsblk");
	printf("choose source drive: ");
	scanf("%s", sdrive);
	printf("\n\n");
	clearBuf();
	
	snprintf(command, sizeof(command), "lsblk | grep -Ev '%s'", sdrive);
	system(command);
	printf("choose target drive: ");
	scanf("%s", tdrive);
	clearBuf();

	printf("Specify a bs value? Default is 512. (Y/N): ");
	c = malloc (2);
	fgets (c, 2, stdin);
	choice = *c;
	choice = toupper(choice);
	clearBuf();

	if(choice == 'Y'){
		printf("Please input a byte size value: ");
		scanf("%d", &bsInt);
	}
	if(choice == 'N'){
		bsInt = 512;
	}
	else{
		bsInt = 512;
	}
	
	system("clear && lsblk");
	printf("Clone %s onto %s? (Y/N):", sdrive, tdrive);
	c = malloc (2);
	fgets (c, 2, stdin);
	choice = *c;
	choice = toupper(choice);
	clearBuf();

	if(choice == 'Y'){
		printf("copying...");
		snprintf(command, sizeof(command), "sudo dd bs='%d' if=/dev/'%s' | pv | dd of=/dev/'%s'",bsInt, sdrive, tdrive);
		system(command);
	}
	if(choice == 'N'){
		return 0;
	}
	else{
		return 0;
	}
}

int cleanClone(){
	char sdrive[25];
	char tdrive[25];
	char command[100];
	char choice;
	char *c;

	system("clear");
	printf("Clean clone:\n\n");
	system("lsblk");
	printf("choose source drive: ");
	scanf("%s", sdrive);
	printf("\n\n");
	clearBuf();
	
	snprintf(command, sizeof(command), "lsblk | grep -Ev '%s'", sdrive);
	system(command);
	printf("choose target drive: ");
	scanf("%s", tdrive);
	clearBuf();

	system("clear && lsblk");
	printf("Clone %s onto %s? (Y/N):", sdrive, tdrive);
	c = malloc (2);
	fgets (c, 2, stdin);
	choice = *c;
	choice = toupper(choice);
	clearBuf();

	if(choice == 'Y'){
		printf("copying...");
		snprintf(command, sizeof(command), "sudo ddrescue -vf /dev/%s /dev/%s cloneLog.txt",sdrive, tdrive);
		system(command);
	}
	if(choice == 'N'){
		return 0;
	}
	else{
		return 0;
	}
}

void zero(){
	char tdrive[25];
	char choice;	
	char command[100];
	char *c;

	system("clear");
	printf("Zerowrite a drive (use extreme caution)\n");
	system("lsblk");
	printf("choose a drive to zerowrite: ");
	scanf("%s", tdrive);
	clearBuf();
	
	system("clear && lsblk");
	printf("are you sure you want to zerowrite /dev/%s? (Y/N):", tdrive);
	c = malloc (2);
	fgets (c, 2, stdin);
	choice = *c;
	choice = toupper(choice);
	clearBuf();

	if(choice == 'Y'){
		printf("zerowriting...");
		snprintf(command, sizeof(command), "sudo dd if=/dev/zero | pv | dd of=/dev/%s", tdrive);
		system(command);
	}
}

void help(){
	printf("Please specify:\n");
	printf("-d for a dirty clone (uses dd, for know working drives.)\n");
	printf("-c for a clean clone (uses ddrescue, for know bad drives.)\n");
	printf("-z to zerowrite a drive (use extreme caution)\n");
}

int main(int argc, char *argv[])
{	
	char choice;

	if(getuid() != 0){
		printf("Please run clonie as root.\n");
		return 0;
	}

	if(argc <= 1){
		system("clear");
		printf("Will this be a clean or dirty clone?\n");
		printf("(1)Dirty   (2)Clean\n");
		printf("choice: ");
		char *i;
		i = malloc (2);
		fgets (i, 2, stdin);
		choice = *i;
		clearBuf();

		if(choice == '1'){
			dirtyClone();
		}
		if(choice == '2'){
			cleanClone();
		}
	}

	if(argc = 1){
		if(strcmp(argv[1], "-d") == 0){
			dirtyClone();
		}
		if(strcmp(argv[1], "-c") == 0){
			cleanClone(); }
		if(strcmp(argv[1], "-h") == 0){
			help();
		}
		if(strcmp(argv[1], "-z") == 0){
			zero();
		}
	}

return 0;
}
