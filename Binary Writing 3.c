#include <stdio.h>
#include <string.h>
typedef struct storeitem{
    int itemcode;
	char itemname[31];  /* Maximum of 30 characters */
}STOREITEM;

char filemname[] = "./storeitem.dat";

int main()
{
    FILE *f;
	STOREITEM item;
	
	f = fopen(filemname, "rb");
	
	/* Write the content */
	fread(&item, sizeof(STOREITEM), 1, f);
	
	fclose(f);
	
	/* Dsiplay the structure content */
	printf("\nItem Code : %d", item.itemcode);
	printf("\nItem Name : %-30s", item.itemname);
}

void WriteaRecord()
{
	    FILE *f;
	STOREITEM item;
	
	item.itemcode = 1;
	strcpy(item.itemname, "Pencil");
	
	f = fopen(filemname, "wb");
	
	/* Write the content */
	fwrite(&item, sizeof(STOREITEM), 1, f);
	
	fclose(f);
}