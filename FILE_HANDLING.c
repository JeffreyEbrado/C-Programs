/**JEFFREY S.EBRADO 2-G COMP-E**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

/**PASSWORD ON MASTERLIST~
*11999
**/

/*DATA TYPES TO BE USED USING STRUCTURE TO BE USED AS A VARIABLE STORAGE*/
typedef struct {
	
	//common parameters being used in CRUD etc.
    char title[100];
    char author[50];
    char publicationYEAR[30];
    char price[100];
    
    //for adding content used as temporary storage
    char content[3000];
    char FINAL_CONTENT[5000];
    char copied_string[3000];
    
    //for updating files
    char filename[100];
	char NEW_UPDATED_FILENAME[100];
	char UPDATED_FILENAME[100];
	char FINAL_FILENAME[100];
	char ORIGINAL_FILENAME[100];
	
	//renaming file
	char OLDfile[100];
	char NEWfile[100];
    
    FILE *fptr;/**Gain access for file operations**/
    char insideofFILE[100];
    
    char master_list[500];
    
}Book;

    /**Globally declared**/

    Book BOOK;/**Calls the Book using the alias BOOK**/
    
    /* Define the folder directory source path using Fslash or a dot for where u save the program it will be there to open*/
    char folder_path[] = ".";
    
  
  /**FOR DRY PURPOSES
*[ always_remind_text ]
*[ always_remind ]
*[ resetting_memory ]
*[ master_list_part ]
*[ reading_and_copy ]
*[ resetting_memory ]
*[ read_content ]
*[ input ]
*[ file_output ]
**/


/**Just a guide if the void always_remind is on it**/
void always_remind_text() {
	printf("\t\tO----------------------------------O\n");
    printf("\t\t|TO GO BACK TO MAIN MENU, INPUT '0'|\n");/**Printed Guide what did the user select to do**/
    printf("\t\t|TO EXIT THE PROGRAM, INPUT '00'   |\n");/**Printed Guide what did the user select to do**/
    printf("\t\tO----------------------------------O\n");
}

/**Just in case for implicit problems**/
void menu(){
	main();
}


void resetting_memory(){
	
	/**sets the buffer inside of a variable**/
	
		memset(BOOK.title, 0, sizeof(BOOK.title));
		memset(BOOK.author, 0, sizeof(BOOK.author));
		memset(BOOK.publicationYEAR, 0, sizeof(BOOK.publicationYEAR));
		memset(BOOK.price, 0, sizeof(BOOK.price));
		memset(BOOK.filename, 0, sizeof(BOOK.filename));
		memset(BOOK.NEWfile, 0, sizeof(BOOK.NEWfile));
		memset(BOOK.OLDfile, 0, sizeof(BOOK.OLDfile));
	
}


/**Always compares the input of these parameters being assign,
*To check 
*   if the user input "0" then it will return to main menu,
*and
*   if the user inputs "00" then it will exit the program**/

void always_remind() {

    if (strcmp(BOOK.title, "00") == 0 || strcmp(BOOK.author, "00") == 0 || strcmp(BOOK.publicationYEAR, "00") == 0  || strcmp(BOOK.price, "00") == 0 || strcmp(BOOK.filename, "00") == 0 || strcmp(BOOK.OLDfile, "00") == 0 || strcmp(BOOK.NEWfile, "00") == 0 ){
		
        system("cls");
           
        resetting_memory();

		/**Exits the program**/
		exit(0);
    }

    if (strcmp(BOOK.title, "0") == 0 || strcmp(BOOK.author, "0") == 0 || strcmp(BOOK.publicationYEAR, "0") == 0  || strcmp(BOOK.price, "0") == 0 || strcmp(BOOK.filename, "0") == 0 || strcmp(BOOK.OLDfile, "0") == 0 || strcmp(BOOK.NEWfile, "0") == 0 ){
    	
	    system("cls");
	    
	    //erases the datatype inside of a parameter
	    resetting_memory();
		
		/**Goes back to main menu**/
		main();
    }
}

void yes_no() {
	
    char choice;/**a single parameter to be used on**/

    /***Ask if the user would like to continue back to the main selection or not***/
    do {
        printf("\t\tO--------------------------O\n");
        printf("\t\t| %-24s |\n", "Back to main menu? (y/n)");/**Printed guide thats asks the user**/
        printf("\t\tO--------------------------O\n");
        printf("\t\t -");
        
        scanf(" %c", &choice); /**Reads the input of a user**/
        
        system("cls");/**clears the console above this**/
        
        if (choice == 'n' || choice == 'N') {/**If the user inputs n or N then it is true that goes to the statement**/
        	
            exit(0);/***if the user input what's inside of the condition then the program will exit with a return value of 0***/

        } else if (choice == 'y' || choice == 'Y') {/**If the user inputs y or Y then it is true that goes to the statement**/
        	
            main();/***if the user input what's inside of the condition then the program will return to the main function***/

        } else { /**If the user inputs is not belong to those condtions**/
        
        system("color 04");
        
          printf("\t\tO--------------------------O\n");
          printf("\t\t| %-24s |\n", "INVALID CHOICE!!!");

        }
        
    } while (1); /** Infinite loop since its always true=1**/

    system("cls");/**clears the console above this**/

}

void inputs(){
	
	printf("\t\t TITLE:");/**Printed Guide**/
    fgets(BOOK.title, 100, stdin);
    BOOK.title[strlen(BOOK.title) - 1] = '\0';
    always_remind();
    
    printf("\t\t AUTHOR:");
    fgets(BOOK.author, 100, stdin);
    BOOK.author[strlen(BOOK.author) - 1] = '\0';
    always_remind();
	
}

/**Used in create, update and update_content**/
void file_output(){
	
	    fprintf(BOOK.fptr, "TITLE: %s\n", BOOK.title);
        fprintf(BOOK.fptr, "AUTHOR: %s\n", BOOK.author);
        fprintf(BOOK.fptr, "PUBLICATION YEAR: %s\n", BOOK.publicationYEAR);
        fprintf(BOOK.fptr, "PRICE: %s\n", BOOK.price);

}

/**The variable beside void is waiting to be called for Creating Books**/
void add_content(){

    printf("\t\tO----------------------------------------------------O\n");
    printf("\t\t| %-45s |\n", "INPUT THE INFO OF THE BOOK YOU WANT TO ADD CONTENT");
    printf("\t\tO----------------------------------------------------O\n");
    
    always_remind_text();
    
    getchar();/**Makes the program only reads one input**/
    
    /**INPUT DATA**/
    inputs();

    /**Makees the title and author become one to become the filename of the book**/
    sprintf(BOOK.filename, "%s-%s.txt", BOOK.title, BOOK.author);
    
    /**Access the file operatons using 'fptr' is equal to opening the filename by reading **/
    BOOK.fptr = fopen(BOOK.filename, "r");
    
    system("cls");
    
    
    if (access(BOOK.filename, F_OK) != 0) {/**if the filename wont be access then the condition is true**/
        system("cls");

        printf("\t\tO---------------------O\n");
        printf("\t\t| %-19s |\n", "FILE DOESN'T EXIST!");/**Printed Guide since the file has been access which will be none(0)**/
        printf("\t\tO---------------------O\n");
		     
      yes_no();/**if the condition is true then the user will return with a value of calling code**/
    }

    fclose(BOOK.fptr);/**Closes the file operation**/
 
   /**combines the inputed strings to combine it and become necessarry to use as a filename**/
    sprintf(BOOK.filename, "%s-%s.txt", BOOK.title, BOOK.author);

    char inside_of_file[5000], BOOK_INFO[5000], FINAL_CONTENT[5000];
    
    BOOK.fptr = fopen(BOOK.filename, "r+");/**Opens the filename in reading and writng**/
    
    /**Reads everthing inside of the file**/
      while (fgets(inside_of_file, sizeof(inside_of_file), BOOK.fptr)) {

    fprintf(BOOK.fptr, "%s", inside_of_file);/**Prints all the inside of filename**/
}

    inside_of_file[strlen(inside_of_file)-1]='\0';/**removes the newline of the parameter and replaces it with null**/
    
    fclose(BOOK.fptr);
    
   do{
   	
    BOOK.fptr = fopen(BOOK.filename, "a");/**opens the file by appending**/
    
    printf("\n\n\n\t\tPress Enter to continue...");
    
    getchar();
    
    system("cls");

    printf("Press 'ENTER' if you are 'DONE' adding a content as a paragraph!!!\n");
	printf("AddContent:");
    fgets(BOOK.content, sizeof(BOOK.content), stdin);
    BOOK.content[strlen(BOOK.content)-1]='\0';
    
    int words_per_line = 7;/**size to words every line**/
    char copy[1000];
    
    strcpy(copy, BOOK.content);

    char* token = strtok(copy, " ");/**Uses a space as a delimeter or sign to be used later**/
    int word_count = 1;
    char content_with_line_breaks[1000];

    	sprintf(content_with_line_breaks,"\n\t-");/**How the content should be print at the beginning**/
    	strcpy(FINAL_CONTENT, content_with_line_breaks);/**Transer it to the parameter to used as an output**/
    	
 
    while (token != NULL) { /**loops until the token or the space is equal to null**/
    
        strcat(FINAL_CONTENT, token);/**token connects to final_content means all the string inside of it that has a space will become the delimeter for adding newline**/
        strcat(FINAL_CONTENT, " ");

        if (word_count % words_per_line == 0) {/**where the word_count reaches(7) divided words_per_line reaches(7) = 0 then it is true*/
            strcat(FINAL_CONTENT, "\n\t");/**adds newine and tab that links to final_content**/
        }

        token = strtok(NULL, " ");
        word_count++; /*adds 1 when space exist*/
        
    }
    /*OUTPUT*/
    sprintf(FINAL_CONTENT,"%s", FINAL_CONTENT);
    FINAL_CONTENT[strlen(FINAL_CONTENT)-1]='\0';
    
    /*Resets the memory*/
    memset(inside_of_file, 0, sizeof(inside_of_file));
    memset(BOOK_INFO, 0, sizeof(BOOK_INFO));
    
    // Write content with line breaks to the file
    fprintf(BOOK.fptr, "\n%s", FINAL_CONTENT);
    
    system("cls");
    
    /*Resets the memory*/
    memset(FINAL_CONTENT, 0, sizeof(FINAL_CONTENT));

    fclose(BOOK.fptr);

    printf("\t\tO-----------------------------------------------O\n");
    printf("\t\t| %-45s |\n", "YOU HAVE SUCCESSFULLY ADDED CONTENT!");
    printf("\t\tO-----------------------------------------------O\n");
    
   char choice;
   
      up:

        printf("\t\tDO YOU WANT TO ADD ANOTHER CONTENT?(y/n): ");
        scanf(" %c", &choice); // Notice the space before %c to consume the newline character.

        if (choice == 'n' || choice == 'N') {
        	
        	system("cls");
        	
        	memset(BOOK.title, 0, sizeof(BOOK.title));
	     	memset(BOOK.author, 0, sizeof(BOOK.author));
	     	
            main();
            
        } else if (choice == 'y' || choice == 'Y') {
            // Continue the loop, no need for any action here.
            memset(BOOK.content, 0, sizeof(BOOK.content));
        } else {
        	
        	system("cls");
        	
            system("color 04");
            
          printf("\t\tO--------------------------O\n");
          printf("\t\t| %-24s |\n", "INVALID CHOICE!!!");
          printf("\t\tO--------------------------O\n");

            goto up;
        }
        memset(BOOK.content, 0, sizeof(BOOK.content));
        
    } while (1);
}


void reading_and_copy(){
   
    fgets(BOOK.insideofFILE, sizeof(BOOK.insideofFILE), BOOK.fptr);
    strcpy(BOOK.title, BOOK.insideofFILE + strlen("TITLE: "));//makes the fgets specifically read the title by maximizing it
    BOOK.title[strlen(BOOK.title) - 1] = '\0';
    

    fgets(BOOK.insideofFILE, sizeof(BOOK.insideofFILE), BOOK.fptr);
    strcpy(BOOK.author, BOOK.insideofFILE + strlen("AUTHOR: "));
    BOOK.author[strlen(BOOK.author) - 1] = '\0';

    fgets(BOOK.insideofFILE, sizeof(BOOK.insideofFILE), BOOK.fptr);
    strcpy(BOOK.publicationYEAR, BOOK.insideofFILE + strlen("PUBLICATION YEAR: "));
    BOOK.publicationYEAR[strlen(BOOK.publicationYEAR) - 1] = '\0';

    fgets(BOOK.insideofFILE, sizeof(BOOK.insideofFILE), BOOK.fptr);
    strcpy(BOOK.price, BOOK.insideofFILE + strlen("PRICE: "));
    BOOK.price[strlen(BOOK.price) - 1] = '\0';
    
    fclose(BOOK.fptr);
	
	
}


void master_list_part(){
	
	//master list part
    char master_list[50] = "MASTER-LIST.dat";
    int headerPrinted = 0;

    DIR *dir;
    struct dirent *entry;
    
    dir = opendir(folder_path); 
    
    /*TRIAL TO KNOW IF OPENING THE FILEPATH EXIST OR NOT*/
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    BOOK.fptr = fopen(master_list, "w");
    /*TRIAL TO KNOW IF OPENING THE FILE MASTER-LIST.data EXIST OR NOT*/
    if (BOOK.fptr == NULL) {
        perror("Error opening MASTER-LIST.dat");
        closedir(dir);
        exit(EXIT_FAILURE);
    }
    char combined[200];

    sprintf(combined, "| %-15s | %-15s | %-17s | %-10s | %-30s | %-13s |\n","TITLE", "AUTHOR", "PUBLICATION YEAR", "PRICE", "FILENAME", "IS RENAMED=1");
         combined[strlen(combined)-1]='\0';   
        fprintf(BOOK.fptr, "%s\n", combined);
          
            fclose(BOOK.fptr);


    while ((entry = readdir(dir)) != NULL) {
        if (ends_with(entry->d_name, ".txt")) {
            BOOK.fptr = fopen(entry->d_name, "r");
            if (BOOK.fptr != NULL) {
			if(strcmp(entry->d_name, "MASTER-LIST.dat") != 0){
   
                char insideofFILE[100];
                
                reading_and_copy();

                BOOK.fptr = fopen(master_list, "a");
                
                char COMBINED[300];
                char master_list_filename[50], master_list_filename2[50];
                sprintf(master_list_filename, "%s",entry->d_name);
                sprintf(master_list_filename2, "%s-%s.txt", BOOK.title, BOOK.author);
                
                char IS_RENAMED_OR_NOT[10], RENAMED[]="1", NOT_RENAMED[]="0";
                          
                if(strcmp(master_list_filename, master_list_filename2)==0){
                	strcpy(IS_RENAMED_OR_NOT, NOT_RENAMED);
				} else {
						strcpy(IS_RENAMED_OR_NOT, RENAMED);
				}
			
                sprintf(COMBINED, "| %-15s | %-15s | %-17s | %-10s | %-30s | %-13s |\n",
                        BOOK.title, BOOK.author, BOOK.publicationYEAR, BOOK.price, master_list_filename, IS_RENAMED_OR_NOT);
                        COMBINED[strlen(COMBINED)-1]='\0';
                        fprintf(BOOK.fptr, "%s\n", COMBINED);

                fclose(BOOK.fptr);
               }
            }
        }
    }


    fclose(BOOK.fptr);
    closedir(dir);

	
}

/**Used in read_file and updating_content**/
void read_content(){
	
	 BOOK.fptr = fopen(BOOK.filename, "r");

    // Find the size of the file
    fseek(BOOK.fptr, '\0', SEEK_END);
    
    long file_size = ftell(BOOK.fptr);
    rewind(BOOK.fptr);

    // Allocate memory to store the file content
    char *file_content = (char *)malloc(file_size + 1);

    // Read the entire file into file_content
    fread(file_content, sizeof(char), file_size, BOOK.fptr);
    
    file_content[file_size] = '\0'; // Null-terminate the string

    // Find the string that starts with '-' and ends with '\0'
    char *start = strchr(file_content, '-');
    char *end = strchr(start, '\0');

    // Calculate the length of the string to be copied
    size_t length = end - start;

    // Allocate memory to store the copied string
    char *copied_string = (char *)malloc(length + 1);

    // Copy the string using strcpy
    strncpy(copied_string, start, length);
    strcpy(BOOK.copied_string, copied_string);
    
    free(file_content);
    free(copied_string);

}

/**Where the file can be created with a user**/
void create() {
	
	always_remind_text();

    printf("\t\tO-----------------------------------------------O\n");
    printf("\t\t| %-45s |\n", "INPUT THE INFO OF THE BOOK YOU WANT TO CREATE");/**Printed Guide what did the user select to do**/
    printf("\t\tO-----------------------------------------------O\n");
    
    getchar();/**Makes the program only reads one input**/
    
    /**INPUT DATA**/
    inputs();

    /**Makees the title and author become one to become the filename of the book**/
    sprintf(BOOK.filename, "%s-%s.txt", BOOK.title, BOOK.author);
    
    /**Access the file operatons using 'fptr' is equal to opening the filename by reading **/
    BOOK.fptr = fopen(BOOK.filename, "r");
    
    /**Condition says if the filename has been access then it will be compared to F_OK means exist equals to zero means the file exist**/
    if (access(BOOK.filename, F_OK) == 0) {
        system("cls");

        printf("\t\tO---------------------O\n");
        printf("\t\t| %-19s |\n", "FILE ALREADY EXIST!");/**Printed Guide since the file has been access which will be none(0)**/
        printf("\t\tO---------------------O\n");

        
        yes_no();/**if the condition is true then the user will return with a value of calling code**/
    }

    fclose(BOOK.fptr);/**Closes the file operation**/

    printf("\t\t PUBLICATION YEAR:");
    fgets(BOOK.publicationYEAR, 100, stdin);
    BOOK.publicationYEAR[strlen(BOOK.publicationYEAR) - 1] = '\0';
    always_remind();
    
    printf("\t\t PRICE:");
    fgets(BOOK.price, 100, stdin);
    BOOK.price[strlen(BOOK.price) - 1] = '\0';
    always_remind();

    /**Access the file operatons using 'fptr' is equal to opening the filename by writing **/
    BOOK.fptr = fopen(BOOK.filename, "w");
    
    /**OUTPUT DATA**/
    file_output();
    
    fclose(BOOK.fptr);

    system("cls");/**clears the console above this**/

   /**Parameter for creating the master list data**/
    
    sprintf(BOOK.master_list, "MASTER-LIST.dat");/**stores the string to parameter**/
    
    /**Condition says if the filename has been access then it will be compared to F_OK means exist equals to zero means the file exist**/
    if (access(BOOK.master_list, F_OK) == -1) {
    	
        BOOK.fptr = fopen(BOOK.master_list, "w");/**Accessing the file using the pointer which will be equal to opening the master_list by writing**/
        
        /**OUTPUT DATA**/
        fprintf(BOOK.fptr, "| %-15s | %-15s | %-17s | %-10s | %-30s | %-13s |\n", "TITLE", "AUTHOR", "PUBLICATION YEAR", "PRICE", "FILENAME", "IS RENAMED=1");/**Prints the assigned strings orderly inside of the file**/
        fprintf(BOOK.fptr, "| %-15s | %-15s | %-17s | %-10s | %-30s | %-13s |\n",
        BOOK.title, BOOK.author, BOOK.publicationYEAR, BOOK.price, BOOK.filename, "0");/**Prints the inputed strings orderly inside of the file**/

    } else {/**If the master list already exist**/
        // In case the master list already exists, just append the new book information
        BOOK.fptr = fopen(BOOK.master_list, "a");
        fprintf(BOOK.fptr, "| %-15s | %-15s | %-17s | %-10s | %-30s | %-13s |\n",
        BOOK.title, BOOK.author, BOOK.publicationYEAR, BOOK.price, BOOK.filename, "0");/**Prints the inputed strings orderly inside of the file**/
            
    }

    fclose(BOOK.fptr);/**Closes the file operation**/

    printf("\t\tO-----------------------------------------------O\n");
    printf("\t\t| %-45s |\n", "YOU HAVE SUCCESSFULLY CREATED A FILE!!!");
    printf("\t\tO-----------------------------------------------O\n");
    
    yes_no();/**Calls the void of yes_no function**/
    
}

/**Where the user can read using this process**/
void readBook() {
	
	always_remind_text();//calling code
	
    printf("\t\tO-----------------------------------------------O\n");
    printf("\t\t| %-45s |\n", "INPUT THE INFO OF THE BOOK YOU WANT TO READ");
    printf("\t\tO-----------------------------------------------O\n");
    
    getchar();

    /**INPUT**/
    inputs();

    sprintf(BOOK.filename, "%s-%s.txt", BOOK.title, BOOK.author);

    system("cls"); // clears the console of the inputs or above inside of this void

    // OUTPUT in the compiler
    if (access(BOOK.filename, F_OK) == -1) {
    	
    	/**if the condition fptr, which is opening the filename to read, is NULL or can't be found, then this will be printed**/
 
        printf("\t\tO---------------------O\n");
        printf("\t\t| %-19s |\n", "FILE DOESN'T EXIST!");
        printf("\t\tO---------------------O\n");
        
        yes_no();
        
    } else {
    	
        char infile[100]; // A variable that I'm going to use to print the inside of the file on the compiler
        
    printf("\t\tO-----------------------------------------------O\n");
    printf("\t\t| %-45s |\n", "YOU HAVE SUCCESSFULLY READ A FILE!!!");
    printf("\t\tO-----------------------------------------------O\n");
    
    BOOK.fptr = fopen(BOOK.filename, "r"); // fptr calls the FILE * to operate a file, which is opening the actual filename to read the inside of the file
        
    reading_and_copy();
    
    }
    
do{

	/*OUTPUT*/
	printf("\t\tO--------------------------------O\n");
    printf("\t\t| %-30s |\n", "BOOK INFORMATION!!!");
	printf("\t\t|--------------------------------O\n");
    printf("\t\t|TITLE: %-24s |\n", BOOK.title);
    printf("\t\t|AUTHOR: %-23s |\n", BOOK.author);
    printf("\t\t|PUBLICATION YEAR: %-13s |\n", BOOK.publicationYEAR);
    printf("\t\t|PRICE: %-24s |\n", BOOK.price);
	printf("\t\tO--------------------------------O\n");

    int choice;
    char number[50];
    char IN_file[100], final_IN_file[100], price_part[100];

    BOOK.fptr = fopen(BOOK.filename, "r");

    while (fgets(IN_file, sizeof(IN_file), BOOK.fptr)) {
    	
    strcpy(price_part, IN_file + strlen("PRICE: ") );
    price_part[strlen(price_part)-1]='\0';
    
   }

    if (strcmp(price_part, BOOK.price) == 0) {
        strcpy(number, "(1)NONE");
    } else {
        strcpy(number, "(1)NEXT");
    }
    fclose(BOOK.fptr);

	
    
    printf("\n\t\t%s\n\t\t(2)PREVIOUS\n\t\t(3)BACK TO MAIN MENU\n\t\t(4)EXIT THE PROGRAM ", number);
	printf("\n\t\tSELECT FROM (1-4):");
    scanf("%d", &choice);
    
    if(choice == 1){
    	
    if (strcmp(price_part, BOOK.price) == 0){
    	
    	system("cls");
    	
        printf("\t\tO---------------------O\n");
        printf("\t\t| %-19s |\n", "CONTENT EMPTY!");
        printf("\t\tO---------------------O\n");
        
    	goto here;
	} 
	
	read_content();

    system("cls");
    printf("CONTENT: \n\t%s", BOOK.copied_string);
    
    // Clean up and close the file
    memset(BOOK.copied_string, 0, sizeof(BOOK.copied_string));
    fclose(BOOK.fptr);

   }else if(choice == 2){
	
 	system("cls");
    printf("\t\tO--------------------------------O\n");
    printf("\t\t| %-30s |\n", "NOTHING CAN BE FOUND!!!");
    printf("\t\tO--------------------------------O\n");
	
  } else if(choice == 3){
	
	system("cls");/**IN PROGRESS for updating only a paragraph**/
	main();
	
  } else if(choice == 4){
	
	system("cls");
	exit(0);
	
  } else {
	
	system("cls");
	
          printf("\t\tO--------------------------O\n");
          printf("\t\t| %-24s |\n", "INVALID CHOICE!!!"); 
          printf("\t\tO--------------------------O\n");
          
    yes_no();
  }
  here:
  	
   printf("\n\t\t(2)PREVIOUS\n\t\t(3)BACK TO MAIN MENU\n\t\t(4)EXIT THE PROGRAM \n\n\t\tSELECT FROM (1-4):");
   scanf("%d", &choice);

  if(choice == 1){
	
	system("cls");
          printf("\t\tO-----------------O\n");
          printf("\t\t| %-15s |\n", "THE END!!!"); 
          printf("\t\tO-----------------O\n");
          
          yes_no();
	
   }  else if(choice == 2){
 	
 	system("cls");
   /*goes down to while loop*/
   } else if(choice == 3){
	
	system("cls");
	main();
	
   }  else if(choice == 4){
	
	system("cls");
	exit(0);
	
   } else {
	
	system("cls");
	
        printf("\t\tO--------------------------O\n");
        printf("\t\t| %-24s |\n", "INVALID CHOICE!!!");
        printf("\t\tO--------------------------O\n");
          
    yes_no();
}

}while(1);

    // calls the void of it and asks if the user would like to continue back to the main selection or not
    yes_no();
}

/**being able to represent multiple words **/
int ends_with(const char *string, const char *suffix) {
    int string_len = strlen(string);
    int suffix_len = strlen(suffix);
    return strncmp(string + string_len - suffix_len, suffix, suffix_len) == 0;
}


void update() {
	
	always_remind_text();
    getchar();
    
    printf("\t\tO-----------------------------------------------------O\n");
    printf("\t\t| %-46s |\n", "INPUT THE EXACT INFO OF THE BOOK YOU WANT TO UPDATE");
    printf("\t\tO-----------------------------------------------------O\n");
    

    /* INPUT */
    inputs();

    system("cls");

    sprintf(BOOK.filename, "%s-%s.txt", BOOK.title, BOOK.author);
    char COPIEDfilename[100];
    strcpy(COPIEDfilename, BOOK.filename);

    if (access(BOOK.filename, F_OK) != 0) {
    	
        printf("\t\tO---------------------O\n");
        printf("\t\t| %-19s |\n", "FILE DOESN'T EXIST!");
        printf("\t\tO---------------------O\n");
        return yes_no();
        
    } 
	 do  {

    BOOK.fptr = fopen(BOOK.filename, "r");
    
    if(access(BOOK.filename, F_OK)==0){
	} else {
		BOOK.fptr = fopen(BOOK.UPDATED_FILENAME, "r");
	}

    reading_and_copy();
    
    /**To be used in first loop**/
    sprintf(BOOK.ORIGINAL_FILENAME, "%s", BOOK.filename);       
    sprintf(BOOK.NEW_UPDATED_FILENAME, "%s-%s.txt", BOOK.title, BOOK.author);
    /**To be used in second loop**/
  	    
    if(strcmp(BOOK.ORIGINAL_FILENAME, BOOK.NEW_UPDATED_FILENAME)==0){

    strcpy(BOOK.FINAL_FILENAME, BOOK.ORIGINAL_FILENAME);
 	
	} else {
					
	strcpy(BOOK.FINAL_FILENAME, BOOK.NEW_UPDATED_FILENAME);
							
	}
	
    int choice;
    POP_UP:

        printf("\t\tO------------------------------------------O\n");
        printf("\t\t|%-40s |\n", "FILE EXIST CONTINUE TO UPDATE THE BOOK!!!");
        printf("\t\tO------------------------------------------O\n");
        printf("\t\t|(1) %-37s |\n", BOOK.title);
        printf("\t\t|(2) %-37s |\n", BOOK.author);
        printf("\t\t|(3) %-37s |\n", BOOK.publicationYEAR);
        printf("\t\t|(4) %-37s |\n", BOOK.price);
        printf("\t\t|%-41s |\n", "(5) GOTO MENU");
        printf("\t\t|%-41s |\n", "(6) EXIT");
        printf("\t\tO------------------------------------------O\n");
        printf("\t\tSELECT FROM(1-6):");
        
        scanf("%d", &choice);
        
        system("cls");
        
        always_remind_text();

        if (choice == 1) {
        	
            getchar();
            
            printf("\t\tO----------------------------------------O\n");
            printf("\t\t|Current Title: %s \n", BOOK.title);
            printf("\t\tO----------------------------------------O\n");
            printf("\t\tEnter the New Title: ");
            fgets(BOOK.title, 100, stdin);
			BOOK.title[strlen(BOOK.title) - 1] = '\0';


        } else if (choice == 2) {
        	
            getchar();
            
            printf("\t\tO----------------------------------------O\n");
            printf("\t\t|Current Author: %s \n", BOOK.author);
            printf("\t\tO----------------------------------------O\n");
            printf("\t\tEnter the New Author: ");
            fgets(BOOK.author, 100, stdin);
            BOOK.author[strlen(BOOK.author) - 1] = '\0';

            
        } else if (choice == 3) {
        	
            getchar();
            
            printf("\t\tO----------------------------------------O\n");
            printf("\t\t|Current Publication Year: %s \n", BOOK.publicationYEAR);
            printf("\t\tO----------------------------------------O\n");
            printf("\t\tEnter the New Publication Year: ");
            fgets(BOOK.publicationYEAR, 100, stdin);
            BOOK.publicationYEAR[strlen(BOOK.publicationYEAR) - 1] = '\0';

            
        } else if (choice == 4) {
        	
            getchar();
            
            printf("\t\tO----------------------------------------O\n");
            printf("\t\t|Current Price: %s \n", BOOK.price);
            printf("\t\tO----------------------------------------O\n");
            printf("\t\tEnter the New Price: ");
            fgets(BOOK.price, 100, stdin);
            BOOK.price[strlen(BOOK.price) - 1] = '\0';

        } else if (choice == 5) {
        	
        	system("cls");
            main();
            
        } else if (choice == 6) {
        	
        	system("cls");
            exit(0); //exits the program
            
        } else {
		
		system("cls"); 
		      	
        printf("\t\tO--------------------------O\n");
        printf("\t\t| %-24s |\n", "INVALID CHOICE!!!");
        printf("\t\tO--------------------------O\n");
        
            goto POP_UP;        
            
        }
    
        fclose(BOOK.fptr);
        
        system("cls");
        
        if(access(BOOK.filename, F_OK)!=-1){
        	
        	BOOK.fptr = fopen(BOOK.ORIGINAL_FILENAME, "w");
        	strcpy(BOOK.UPDATED_FILENAME, BOOK.ORIGINAL_FILENAME);
        	
	    } else {
	    	
		BOOK.fptr = fopen(BOOK.UPDATED_FILENAME, "w"); 
		
	}
        /**OUTPUT**/
        /**The one will be chosen will be replaced, and those parameters being read beside strcpy will be pasted here**/
        file_output();
        
        fclose(BOOK.fptr);
    
        system("cls");
     
        if(access(BOOK.FINAL_FILENAME, F_OK)!=-1){
		
        BOOK.fptr = fopen(BOOK.FINAL_FILENAME, "r");
        strcpy(BOOK.UPDATED_FILENAME, BOOK.FINAL_FILENAME);/**To be used for infinite loop**/
        
    } else {
    	
    	BOOK.fptr = fopen(BOOK.UPDATED_FILENAME, "r");
	}
	
	/**Reads the file**/
    reading_and_copy();
        
        if(access(BOOK.FINAL_FILENAME, F_OK)!=-1){
        	
        sprintf(BOOK.UPDATED_FILENAME, "%s-%s.txt", BOOK.title, BOOK.author);
        
        rename(BOOK.FINAL_FILENAME, BOOK.UPDATED_FILENAME);
        
    } else {
    		
    	sprintf(BOOK.NEW_UPDATED_FILENAME, "%s-%s.txt", BOOK.title, BOOK.author);
    	
        rename(BOOK.UPDATED_FILENAME, BOOK.NEW_UPDATED_FILENAME);
        strcpy(BOOK.UPDATED_FILENAME, BOOK.NEW_UPDATED_FILENAME);
	}  
        
         printf("\t\tO-----------------------------------------------O\n");
         printf("\t\t| %-45s |\n", "BOOK UPDATED SUCCESSFULLY!");
         printf("\t\tO-----------------------------------------------O\n");
        
    //master list part
    master_list_part();

        
        printf("\t\tDo you still want to continue updating the file? (y/n): ");
        scanf(" %c", &choice); // Reads only one character
        system("cls");
        if (choice == 'n' || choice == 'N') {
            return;//if the user input whats inside of the condition then the program back to the main function
        } else if (choice == 'y' || choice == 'Y') {//if the user input whats inside of the condition then the program will be back to selecting on what you want to update since i dont put what to do it will just read whats below       
        } else {
            printf("INVALID CHOICE!!!\n");//exits the program if the user inputs invalid choice
            exit(0);
        } 
        
    } while (1);
}

/**Where the process of deleting a file**/
void deleteFILE() {
	
	always_remind_text();
	getchar();
	
	printf("\t\tO-----------------------------------------------O\n");
    printf("\t\t| %-45s |\n", "INPUT THE INFO OF THE BOOK YOU WANT TO DELETE");
    printf("\t\tO--------------------------O--------------------O\n");
    printf("\t\t| %-24s |\n", "'filename'.txt");
    printf("\t\tO--------------------------O\n");
    
    printf("\t\t-");
    
	fgets(BOOK.filename,100,stdin);//reads the string to be stored in filename, max size of the input can be read, what the user inputed it will remain as it is
	BOOK.filename[strlen(BOOK.filename)-1]='\0';//ensures to remove the newline of the inputed by user
	always_remind();
	
	sprintf(BOOK.filename, "%s.txt", BOOK.filename);
	
	system("cls");

    if (remove(BOOK.filename) == 0) {

        printf("\t\tO------------------------------------------------O\n");
        printf("\t\t| %-46s |\n", "YOU HAVE SUCCESSFULLY DELETED A FILE!!!");
        printf("\t\tO------------------------------------------------O\n");
        
    } else {
        
        printf("\t\tO------------------------------------------------O\n");
        printf("\t\t| %-46s |\n", "FAILED TO DELETE A FILE");
        printf("\t\tO------------------------------------------------O\n");
    }
   
   //master list part 
   master_list_part();
    
    
    yes_no();
}


/**Where the process on renaming the file**/
void renameFile() {
	
	always_remind_text();

    getchar(); // To make the inputs not skip and make it read only a single input
    
    // INPUT of OLD filename you want to rename
	printf("\t\tO------------------------------------------------O\n");
    printf("\t\t| %-46s |\n", "ENTER THE OLD 'filename' YOU WANT TO RENAME");
    printf("\t\tO------------------------------------------------O\n");
    
    printf("\t\t-");
        
    fgets(BOOK.OLDfile, 100, stdin); // reads the string to be stored in filename, max size of the input can be read, what the user inputted it will remain as it is
    BOOK.OLDfile[strlen(BOOK.OLDfile) - 1] = '\0'; // ensures to remove the newline of the input entered by the user
    always_remind();
    
    sprintf(BOOK.OLDfile, "%s.txt",BOOK.OLDfile);
    system("cls");
    if(access(BOOK.OLDfile, F_OK)==-1){
    	
        printf("\t\tO---------------------O\n");
        printf("\t\t| %-19s |\n", "FILE DOESN'T EXIST!");
        printf("\t\tO---------------------O\n");
        
        return yes_no();
	}
    system("cls");
    
    printf("\t\tO------------------------------------------------O\n");
    printf("\t\t| %-46s |\n", "ENTER NEW 'filename'");
    printf("\t\tO------------------------------------------------O\n");
    
    printf("\t\t-");
    
    fgets(BOOK.NEWfile, 100, stdin);
    BOOK.NEWfile[strlen(BOOK.NEWfile) - 1] = '\0';

    system("cls"); // clears the console of the inputs or above inside of this void from here
    
    sprintf(BOOK.NEWfile, "%s.txt",BOOK.NEWfile);

    rename(BOOK.OLDfile, BOOK.NEWfile); 

        printf("\t\tO------------------------------------------------O\n");
        printf("\t\t| %-46s |\n", "OLD FILENAME BOOK SUCCESSFULLY RENAMED!");
        printf("\t\tO------------------------------------------------O\n");
          
   //master list part
   master_list_part();
        
    yes_no(); /*calls the void of it and asks if the user would like to continue back to the main selection or not*/
}


int number = 1; 

void list() {
	
	void print_filename_without_extension(const char *filename);

    DIR *folder;
    struct dirent *entry;

    folder = opendir(folder_path);
    if (folder == NULL) {
        printf("Folder does not exist.\n");
        return yes_no();
    }

    printf("\t\tO------------------------------------------------O\n");
    printf("\t\t| %-46s |\n", "AVAILABLE BOOKS!!!");
    printf("\t\tO------------------------------------------------O\n");

    entry = readdir(folder);
    while (entry != NULL) {
        if (ends_with(entry->d_name, ".txt")) {
            int len = strlen(entry->d_name);
            char filename_without_ext[100]; 
            int j = 0;
            int i = 0;
            while (i < len - 4) {
                if (entry->d_name[i] == '-') {
                    filename_without_ext[j++] = ' '; /**Add 1 space**/
                    filename_without_ext[j++] = 'b'; /*Add 1 b */
                    filename_without_ext[j++] = 'y'; /*Add 1 y */
                    filename_without_ext[j++] = ' '; /*Add 1 space after "by"*/
                } else {
                    filename_without_ext[j++] = entry->d_name[i]; /**Filename will be the same if it doesnt have '-'**/
                }
                i++;
            }
            filename_without_ext[j] = '\0';

            printf("\t\t");
            print_filename_without_extension(filename_without_ext); /**Call the function to print the formatted filename**/
            printf("\n");
        }
        entry = readdir(folder);/**Required for making the program at the center and the rest exist**/
    }

    closedir(folder);/**closes the directory stream**/

    printf("\t\tO------------------------------------------------O\n");
    yes_no();
}


void print_filename_without_extension(const char *filename) {
    printf("| (%d) %-42s |", number, filename);/**Necessarry for output without .txt**/
    number++;
}


void master_list() {
    char password[15];
    int number=0;
    

    do {
    	always_remind_text();
        printf("\t\tENTER YOUR PASSWORD:");
        scanf("%s", password);
        system("cls");
        
        // Compare the password with a string instead of an integer
        if (strcmp(password, "11999") == 0) {
            // Password is correct, break out of the loop
            break;
        } else if(strcmp(password, "0")==0){
        	main();
        	break;
		} else if(strcmp(password, "00")==0){
			exit(0);
			break;
		} else {
			printf("Attempt/s: %d\n", number++);
            printf("\t\tO------------------------------------------O\n");
            printf("\t\t| PASSWORD INCORRECT!!! Please Try again...|\n"); // printed guide
            printf("\t\tO------------------------------------------O\n");
        }
    } while (1);

    // Open the file in read mode
    BOOK.fptr = fopen("MASTER-LIST.dat", "r");

    // Check if the file was opened successfully
    if (BOOK.fptr == NULL) {
        printf("Error opening file.\n");
        return; // Exit the function if the file couldn't be opened
    }

    /*Read and print each line in the file*/
    while (fgets(BOOK.insideofFILE, sizeof(BOOK.insideofFILE), BOOK.fptr)) {
        printf("%s", BOOK.insideofFILE);
    }

    // Close the file
    fclose(BOOK.fptr);

     yes_no();

}

/**Where to update the content of the book **/
void update_book_content(){
	
	always_remind_text();
	printf("\t\tO-----------------------------------------------------------O\n");
    printf("\t\t|ENTER THE INFO OF THE BOOK YOU WANT TO UPDATE THE CONTENT  |\n");/**Printed Guide what did the user select to do**/
    printf("\t\tO-----------------------------------------------------------O\n");
    
    getchar();

    // INPUT
     inputs();

    sprintf(BOOK.filename, "%s-%s.txt", BOOK.title, BOOK.author);

    system("cls"); // clears the console of the inputs or above inside of this void

    // OUTPUT in the compiler
    if (access(BOOK.filename, F_OK) == -1) {
    	
    	
        printf("\t\tO---------------------O\n");
        printf("\t\t| %-19s |\n", "FILE DOESN'T EXIST!");
        printf("\t\tO---------------------O\n");
        yes_no();
        
    } else {
    	   
    printf("\t\tO------------------------------------------------------------O\n");
    printf("\t\t| %-58s |\n", "YOU HAVE SUCCESSFULLY OPENED A FILE TO UPDATE THE CONTENT!");/**Printed Guide what did the user select to do**/
    printf("\t\tO------------------------------------------------------------O\n");
   
}

    BOOK.fptr = fopen(BOOK.filename, "r"); 
        
    reading_and_copy();
         	
    read_content();
    
    
    do{
	
   /**Content part**/
   int choice;
 
        printf("\t\t| (1) %-54s |\n", "Update a word only");
        printf("\t\t| (2) %-54s |\n", "Update the paragraph");
        printf("\t\t| (3) %-54s |\n", "Update the whole content");
        printf("\t\t| (4) %-54s |\n", "BACK TO MAIN MENU");
        printf("\t\t| (5) %-54s |\n", "EXIT THE PROGRAM");
        printf("\t\tO------------------------------------------------------------O\n");
        
        printf("\n\t\tSelect what do you want to update in the content(1-5): ");
  
        scanf("%d", &choice);
        system("cls");
        
        if(choice == 1){
        	

    BOOK.fptr = fopen(BOOK.filename, "r");

    read_content();

    system("cls");
    printf("CONTENT: \n\t%s", BOOK.copied_string);

    fclose(BOOK.fptr);
    
    char word_to_replace[100];
    char replacement_word[100];
    
    getchar();

    printf("\nWhat word do you want to replace? ");
    fgets(word_to_replace, sizeof(word_to_replace), stdin);
    word_to_replace[strlen(word_to_replace) - 1] = '\0';

    printf("What word do you want to replace it with? ");
    fgets(replacement_word, sizeof(replacement_word), stdin);
    replacement_word[strlen(replacement_word) - 1] = '\0';

    char *pos = strstr(BOOK.copied_string, word_to_replace);
    if (pos != NULL) {
        // Create a temporary buffer to hold the modified sentence
        char modified_sentence[200];
        
        // Copy the part of the sentence before the found word
        strncpy(modified_sentence, BOOK.copied_string, pos - BOOK.copied_string);
        modified_sentence[pos - BOOK.copied_string] = '\0';
        
        // Concatenate the replacement word
        strcat(modified_sentence, replacement_word);
        
        // Concatenate the rest of the sentence
        strcat(modified_sentence, pos + strlen(word_to_replace));
        
        // Copy the modified sentence back to the original sentence
        strcpy(BOOK.copied_string, modified_sentence);
    }
    
    BOOK.fptr= fopen(BOOK.filename, "w");
    
    /**OUTPUT**/
    file_output();
    
    fprintf(BOOK.fptr, "\t%s", BOOK.copied_string);
    
    memset(BOOK.copied_string, 0, sizeof(BOOK.copied_string));
    
    fclose(BOOK.fptr);
    
    system("cls");
    printf("\t\tO--------------------------------------------------------O\n");
    printf("\t\t|YOU HAVE SUCCESSFULLY UPDATED A WORD TO BOOK CONTENT!!! |\n");/**Printed Guide what did the user select to do**/
    printf("\t\tO--------------------------------------------------------O\n");
    break;
    
  } else if (choice == 2) {
  	
  	 char FINAL_CONTENT[500];
  	
    read_content();

    char first_word[200];
    char last_word[200];
    char replacement_paragraph[2000];
    system("cls");
    
    printf("CONTENT: \n\t%s\n", BOOK.copied_string);
    getchar();

    printf("\nEnter the first word of the paragraph you want to replace:");
    scanf("%s", first_word);

    printf("Enter the last word of the paragraph you want to replace:");
    scanf("%s", last_word);

    getchar(); // Clear the newline character
    printf("Enter the replacement paragraph:");
    fgets(replacement_paragraph, 2000, stdin);
    replacement_paragraph[strlen(replacement_paragraph) - 1] = '\0';

    // Find the position of the paragraph to replace
    char *pos = strstr(BOOK.copied_string, first_word);
    if (pos != NULL && strstr(pos, last_word) != NULL) {
        // Create a temporary buffer to hold the modified string
        char modified_string[2000];

        // Copy the part of the string before the found paragraph
        strncpy(modified_string, BOOK.copied_string, pos - BOOK.copied_string);
        modified_string[pos - BOOK.copied_string] = '\0';

        // Concatenate the replacement paragraph
        strcat(modified_string, replacement_paragraph);

        // Find the position of the end of the paragraph
        char *end_pos = strstr(pos, last_word) + strlen(last_word);

        // Concatenate the rest of the string after the end of the paragraph
        strcat(modified_string, end_pos);

        // Copy the modified string back to the original string
        strcpy(BOOK.copied_string, modified_string);
        BOOK.copied_string[strlen(BOOK.copied_string) - 1] = '\0';
        
       
    int WORDS_PER_LINE = 7;
    char copy[2000];
    strcpy(copy, BOOK.copied_string);
    memset(BOOK.copied_string, 0, sizeof(BOOK.copied_string));

    char* token = strtok(copy, " ");
    int word_count = 1;
    char content_with_line_breaks[2000];

    	sprintf(content_with_line_breaks,"\n\t-");
    	strcpy(FINAL_CONTENT, content_with_line_breaks);
    	
 
    while (token != NULL) {
        strcat(FINAL_CONTENT, token);
        strcat(FINAL_CONTENT, " ");

        if (word_count % WORDS_PER_LINE == 0) {
            strcat(FINAL_CONTENT, "\n\t");
        }

        token = strtok(NULL, " ");
        word_count++;
    }
    sprintf(FINAL_CONTENT,"%s", FINAL_CONTENT);
    FINAL_CONTENT[strlen(FINAL_CONTENT)-1]='\0';

    system("cls");

    fclose(BOOK.fptr);
    }
 
    BOOK.fptr = fopen(BOOK.filename, "w"); // Open the file for writing

    // Write the modified paragraph to the file
    file_output();
    
    fprintf(BOOK.fptr, "\t%s", FINAL_CONTENT);

    // Close the file
    fclose(BOOK.fptr);
    
    system("cls");

    printf("\t\tO------------------------------------------------------------------O\n");
    printf("\t\t| %-46s |\n", "YOU HAVE SUCCESSFULLY UPDATED A PARAGRAPH IN THE BOOK CONTENT!!!");
    printf("\t\tO------------------------------------------------------------------O\n");
    
        memset(FINAL_CONTENT, 0, sizeof(FINAL_CONTENT));
    break;
} else if(choice == 3){
  	
  	BOOK.fptr= fopen(BOOK.filename, "w");
    
    file_output();
    
    fclose(BOOK.fptr);
    
    char FINAL_CONTENT[5000], inside_of_file[5000], BOOK_INFO[5000];
  	getchar();
  	printf("Press 'ENTER' if you are 'DONE' updating the whole content!!!\n");
	printf("Update Content:");
    fgets(BOOK.content, sizeof(BOOK.content), stdin);
    BOOK.content[strlen(BOOK.content)-1]='\0';
    
    BOOK.fptr = fopen(BOOK.filename, "a");

    // Add newline if the word reaches unknown words
    int words_per_line = 7;
    char copy[1000];
    strcpy(copy, BOOK.content);

    char* token = strtok(copy, " ");
    int word_count = 1;
    char content_with_line_breaks[1000];

    	sprintf(content_with_line_breaks,"\n\t-");
    	strcpy(FINAL_CONTENT, content_with_line_breaks);
    	
 
    while (token != NULL) {
        strcat(FINAL_CONTENT, token);
        strcat(FINAL_CONTENT, " ");

        if (word_count % words_per_line == 0) {
            strcat(FINAL_CONTENT, "\n\t");
        }

        token = strtok(NULL, " ");
        word_count++;
    }
    sprintf(FINAL_CONTENT,"%s", FINAL_CONTENT);
    FINAL_CONTENT[strlen(FINAL_CONTENT)-1]='\0';
    
    memset(inside_of_file, 0, sizeof(inside_of_file));
    memset(BOOK_INFO, 0, sizeof(BOOK_INFO));
    
    // Write content with line breaks to the file
    fprintf(BOOK.fptr, "\n%s", FINAL_CONTENT);
    
    system("cls");
    
    memset(FINAL_CONTENT, 0, sizeof(FINAL_CONTENT));

    fclose(BOOK.fptr);

    printf("\n\t\t*******************************************\n");
    printf("\t\tYOU HAVE SUCCESSFULLY UPDATED CONTENT!\n");
    printf("\t\t*******************************************\n");
    
    printf("\t\tO------------------------------------------------------------------O\n");
    printf("\t\t| %-46s |\n", "YOU HAVE SUCCESSFULLY UPDATED CONTENT!");
    printf("\t\tO------------------------------------------------------------------O\n");
    break;
  	
  } else if(choice == 4){
  	main();
  } else if(choice == 5){
  	exit(0);
   }else{
        printf("\t\tO--------------------------O\n");
        printf("\t\t| %-24s |\n", "INVALID CHOICE!!!");
        printf("\t\tO--------------------------O\n");

   }
  }while(1);
  yes_no();
}



/**Main Function**/
int main() {

    system("cls");

    
    int selection;
    char shutdown[20];


    do {
    	system("color 03");
        printf("\n\n\n");
        
        printf("\t\tO---------------------------------------O\n");
        printf("\t\t| %-36s |\n", "WELCOME TO THE BOOK MANAGEMENT SYSTEM");
        printf("\t\t|---------------------------------------|\n");
        printf("\t\t| 1. %-34s |\n", "CREATE BOOK INFORMATION");
        printf("\t\t| 2. %-34s |\n", "READ BOOK INFORMATION AND CONTENT");
        printf("\t\t| 3. %-34s |\n", "UPDATE BOOK INFORMATION");
        printf("\t\t| 4. %-34s |\n", "DELETE BOOK INFORMATION");
        printf("\t\t| 5. %-34s |\n", "RENAME BOOK FILENAME");
        printf("\t\t| 6. %-34s |\n", "LIST AVAILABLE BOOKS");
        printf("\t\t| 7. %-34s |\n", "MASTER LIST BOOK INFORMATION");
        printf("\t\t| 8. %-34s |\n", "ADD BOOK CONTENT");
        printf("\t\t| 9. %-34s |\n", "UPDATE BOOK CONTENT");
        printf("\t\t|---------------------------------------|\n");
        printf("\t\t| 10. %-33s |\n", "EXIT");
        printf("\t\tO---------------------------------------O\n");
        printf("\t\t ENTER YOUR SELECTION(1-10): ");
        
        scanf("%d", &selection);

        switch (selection) {
            case 1:
            	system("cls");
                create();
                break;

            case 2:
            	system("cls");
                readBook();
                break;

            case 3:
            	system("cls");
                update();
                break;

            case 4:
            	system("cls");
                deleteFILE();
                break;
                
            case 5:
            	system("cls");
            	renameFile();
            	break;
           	
            case 6:
            	system("cls");
                number = 1; // Reset the global number variable to 1 before listing the books
                list();
                break;
                
            case 7:
            	system("cls");
            	master_list();
            	break;
            	
            case 8:
            	system("cls");
                add_content();
                break;
                
            case 9:
            	system("cls");
                update_book_content();
                break;
                
            case 10:
            	system("cls");
            	sprintf(shutdown, "Shutting down...");
            	printf(shutdown);
                exit(0);
                break;
                
          default:         	
            	system("cls");
            	system("color 04");           	
                yes_no();  
                break;
                
        }
        
    } while (1);
    
}

