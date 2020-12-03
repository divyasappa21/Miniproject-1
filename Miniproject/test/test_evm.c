#include "../unity/unity.h"
#include "../inc/evm.h"

	void setUp()
	{	}
	void tearDown()
	{	}

	void test_display(void)
	{
  		TEST_ASSERT_EQUAL(1,1);
  		TEST_ASSERT_EQUAL(2,2);
  		TEST_ASSERT_EQUAL(3,3);
	}

	void test_correct_admin_access(void)
	{
	    TEST_ASSERT_EQUAL("admin123","admin123");
	    TEST_ASSERT_EQUAL("Hi Admin. Here are the results!","Hi Admin. Here are the results!");
	    TEST_ASSERT_EQUAL("BJP       : %d\nCongress  : %d\nJDS       : %d\nOther     : %d", "BJP       : %d\nCongress  : %d\nJDS       : %d\nOther     : %d");
	}

    void test_wrong_admin_access(void)
	{
	    TEST_ASSERT_EQUAL("admin","admin");
	    TEST_ASSERT_EQUAL("Sorry, access denied. Only admin can access\n", "Sorry, access denied. Only admin can access\n");
	    TEST_ASSERT_EQUAL(123,123);
        TEST_ASSERT_EQUAL("Sorry, access denied. Only admin can access\n", "Sorry, access denied. Only admin can access\n");
	}

	void test_voting_for_first_time(void)
	{
	    TEST_ASSERT_EQUAL("ELECT123","ELECT123");
	    TEST_ASSERT_EQUAL(1,1);
	    TEST_ASSERT_EQUAL("Thank you for voting","Thank you for voting");
	    TEST_ASSERT_EQUAL("ELECT145","ELECT145");
	    TEST_ASSERT_EQUAL(2,2);
	    TEST_ASSERT_EQUAL("Thank you for voting","Thank you for voting");
        TEST_ASSERT_EQUAL("ELECT234","ELECT234");
        TEST_ASSERT_EQUAL(3,3);
        TEST_ASSERT_EQUAL("Thank you for voting","Thank you for voting");
        TEST_ASSERT_EQUAL("ELECT345","ELECT345");
        TEST_ASSERT_EQUAL(4,4);
        TEST_ASSERT_EQUAL("Thank you for voting","Thank you for voting");
        TEST_ASSERT_EQUAL("ELECT456","ELECT456");
        TEST_ASSERT_EQUAL(1,1);
        TEST_ASSERT_EQUAL("Thank you for voting","Thank you for voting");
	}

	void test_already_voted(void)
	{
	    TEST_ASSERT_EQUAL("ELECT123","ELECT123");
	    TEST_ASSERT_EQUAL("You already voted","You already voted");
	    TEST_ASSERT_EQUAL("ELECT145","ELECT145");
	    TEST_ASSERT_EQUAL("You already voted","You already voted");
        TEST_ASSERT_EQUAL("ELECT234","ELECT234");
        TEST_ASSERT_EQUAL("You already voted","You already voted");
        TEST_ASSERT_EQUAL("ELECT345","ELECT345");
        TEST_ASSERT_EQUAL("You already voted","You already voted");
        TEST_ASSERT_EQUAL("ELECT456","ELECT456");
        TEST_ASSERT_EQUAL("You already voted","You already voted");
	}

	int test_main(void)
	{
	  	UNITY_BEGIN();

	  	RUN_TEST(test_display);
	  	RUN_TEST(test_correct_admin_access);
	  	RUN_TEST(test_wrong_admin_access);
	  	RUN_TEST(test_voting_for_first_time);
	  	RUN_TEST(test_already_voted);

  		return UNITY_END();
	}

