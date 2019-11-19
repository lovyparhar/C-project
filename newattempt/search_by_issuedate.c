#include<stdio.h>
#include"structs.h"
void search_by_issuedate(int ni, issuer issue_rec[],int d,int m,int y)
{
	for(int i = 0 ; i < ni ;i++ )
	if( d == issue_rec[i].idate.d && m == issue_rec[i].idate.m && y == issue_rec[i].idate.y)
	{
		printf("%d %s %s %d %d/%d/%d %d/%d/%d %d\n",issue_rec[i].sn,issue_rec[i].iname,issue_rec[i].iid,issue_rec[i].bid,issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine); 

	}

}