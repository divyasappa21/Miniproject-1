#include "../inc/evm.h"
#include "../test/test_evm.h"

int len=0, login;
int party,bjp=0,congress=0,jds=0,other=0;
char voterId[100][10];
char Id[10], p_word[10];
char Success, Failure;

void largestVotes(int bjp,int congress,int jds, int other)
{
	if(bjp>congress&&bjp>jds&&bjp>other)
    {
		printf("The winning party is <<<<<<BJP>>>>>\n");
	}
	else if(congress>bjp&&congress>jds&&congress>other)
	{
		printf("The winning party is <<<<<<Congress>>>>>\n");
	}
	else if(jds>bjp&&jds>congress&&jds>other)
	{
		printf("The winning party is <<<<<<JDS>>>>>\n");
	}
	else if(other>bjp&&other>congress&&other>jds)
	{
		printf("The winning party is <<<<<<Other>>>>>\n");
	}
	else
	{
		printf("There is a tie between parties\n");
	}

}

bool validate_voterId(char *id)
{
    int j=0;
    if(len==0)
    {
        strcpy(voterId[len++],id);
        return true;
    }
    int n= len;
    while(n!=0)
    {
        if(strcmp(voterId[j],id)==0)
        {
            return false;
        }
        j++;
        n--;
    }
    strcpy(voterId[len++],id);
    return true;
}

/*void correct_admin_access();
void wrong_admin_access();
void voting_for_first_time();
void already_voted();*/

void admin()
{
    printf("                                                Welcome Admin                                       \n");
    printf("Enter the password \n");
    scanf("%s",p_word);
    if(strcmp(p_word,"admin123")==0 )
    {
    	printf("\nHi Admin\n");
        printf("Here are the results!\n");
    	printf("\nBJP       : %d\nCongress  : %d\nJDS       : %d\nOther     : %d\n\n", bjp,congress,jds,other);
    	largestVotes(bjp,congress,jds,other);
	}
	else
	{
		printf("Sorry, access denied. Only admin can access\n");
	}
}

void voter()
{
    int log;
    while(1)
    {
        printf("\n                                                   Hi voter                        \n");
        printf("Enter your Voter ID:\n");
        scanf("%s",Id);
        printf("Voter Id is:\n%s\n",Id);
        if(validate_voterId(Id))
        {
            printf("\nWelcome voter!!\n\nWhich party to do want to vote to\n");
            printf("1.BJP \n2.Congress \n3.JDS \n4.Other\n5.NOTA\n");
            scanf("%d",&party);
            switch(party)
            {
                case 1: bjp++;
                        break;
                case 2: congress++;
                        break;
                case 3: jds++;
                        break;
                case 4: other++;
                        break;
                case 5: break;
                default:
                        printf("\nInvalid choice\n");
            }
            printf("\nThank you for voting\n");
        }
        else
        {
            printf("\nYou already voted\n");
            continue;
        }
        printf("\nTo return to login access enter 1 else enter 0\n");
        scanf("%d",&log);
        if(log==0)
        {
            continue;
        }
        else
          return;
    }
}

void display()
{
    while(1)
    {
        printf("\n1. Voter access \n2. Admin access \n3. Exit\n");
        scanf("%d", &login);
        if(login==1)
        {
            voter();
        }
        else if(login==2)
            admin();
        else if(login==3)
            return;
        else
            printf("Invalid input\n");
    }
}
