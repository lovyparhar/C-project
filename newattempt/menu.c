#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"structs.h"
#include"writeread.h"
#include"addsubfine.h"

int main(void)
{
	//Copying file's data to struct
	FILE* readbook;
	readbook = fopen("books.txt", "r");

	if(readbook == NULL){
		FILE* temp;
		temp = fopen("books.txt", "a");
		fclose(temp);

		readbook = fopen("books.txt", "r");
	}

	books book[5000];
	
	int nb = numoflines(readbook);
	writetobs(book, nb, readbook);
	fclose(readbook);

	FILE* readissue;
	readissue = fopen("issue.txt", "r");

	if(readissue == NULL){
		FILE* temp;
		temp = fopen("issue.txt", "a");
		fclose(temp);

		readbook = fopen("issue.txt", "r");
	}

	issuer irecord[5000];
	int ni = numoflines(readissue);
	writetois(irecord, ni, readissue);
	fclose(readissue);
	fine(irecord, ni);




	printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n");

	int o = -1;
	while(o != 0)
	{
		printf("\n1. Display all books\n");
		printf("2. Search books\n");
		printf("3. Display all records\n");
		printf("4. Search records\n");
		printf("5. Display fines\n");
		printf("6. Add Issuer\n");
		printf("7. Delete Issuer\n");
		printf("8. Add book\n");
		printf("9. Delete Book\n");
		printf("10. Book returned\n");
		printf("0. Quit\n");

		printf("\nType an option: ");
		scanf("%d%*c", &o);

		if(o == 1)
		{
			//use display all function
		}

		if(o == 2)
		{
			printf("1. Search by Book Name\n");
			printf("2. Search by Author\n");
			printf("3. Search by Genre\n");
			printf("4. Search by Book ID\n");
			printf("5. Select nothing\n");
		}

		if(o == 3)
		{
			//use display all function
		}

		if(o == 4)
		{
			printf("1. Search by Book Name\n");
			printf("2. Search by Book ID\n");
			printf("3. Search by Issue Date\n");
			printf("4. Search by Issuer Id\n");
			printf("5. Select nothing\n");
		}

		if(o == 5)
		{
			//Display fines
		}

		if(o == 6)
		{
			char iname[100], iid[100];
			int bid, d, m, y;

			printf("\nGive issuer's name : ");
			scanf("%[^\n]%*c", iname);

			printf("\nGive issuer's roll number : ");
			scanf("%[^\n]%*c", iid);

			printf("\nGive book id : ");
			scanf("%d%*c", &bid);

			if(!available(book, bid, &nb)){
				printf("Book not available\n\n");
			}
			else
			{
				printf("\nGive issue date in format d m y : ");
				scanf("%d %d %d%*c", &d, &m, &y);

				addissuer(irecord, book, &ni, &nb, iname, iid, bid, d, m, y);
			}
		}

		if(o == 7)
		{

		}
		if(o == 8)
		{
			int bid; char bname[100], bauthor[100], bgenre[100];

			
			printf("\nGive book ID : ");
			scanf("%d%*c", &bid);

			while(!validbid(book, bid, &nb))
			{
				printf("\nBook ID Exists\n");
				printf("\nGive book ID : ");
				scanf("%d%*c", &bid);
			}

			printf("\nGive the book name : ");
			scanf("%[^\n]%*c", bname);

			printf("\nGive the book author : ");
			scanf("%[^\n]%*c", bauthor);

			printf("\nGive the book genre : ");
			scanf("%[^\n]%*c", bgenre);

			addbook(book, &nb, bid, bname, bauthor, bgenre);
		}
		if(o == 9)
		{
			
		}
		if(o == 10)
		{
			char iid[100]; int d, m, y;

			printf("\nGive the returner's Roll Number : ");
			scanf("%[^\n]%*c", iid);

			while(!ridpresent(irecord, iid, &ni)){
				printf("Roll Number not present\n");
				printf("\nGive the returner's Roll Number : ");
				scanf("%[^\n]%*c", iid);
			}

			printf("\nGive the return date in format d m y: ");
			scanf("%d %d %d%*c", &d, &m, &y);
			addreturndate(irecord, book, iid, &ni, &nb, d, m, y);
		}
	}

	fine(irecord, ni);



	//Saving all the data to the files
	FILE *writebook;
	writebook = fopen("books.txt", "w");

	writetobf(book, nb, writebook);

	fclose(writebook);


	FILE *writeissue;
	writeissue = fopen("issue.txt", "w");

	writetoif(irecord, ni, writeissue);

	fclose(writeissue);

}
