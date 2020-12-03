
/**
* @file evm.h
*/
#ifndef __EVM_H__
#define __EVM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

	/**
	* Calculates votes of each party, diplays the leading party and allows a voter to vote for party
	* @param[in] login to access either admin or voter login
	* @param[in] Id[10] enter the voterID
	* @param[in] party to whom voter wishes to vote
	* @param[in] log to back for either voter or admin login
	* @param[in] p_word[10] enter the password for admin login
	* @return Id
	* @return bjp
	* @return congress
	* @return jds
	* @return others
	* @note Any note for the function
	*/

    void largestVotes(int bjp,int congress,int jds, int other);
    bool validate_voterId(char *id);
    void admin();
    void voter();
    void display();

#endif
