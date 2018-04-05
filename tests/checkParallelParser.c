//
// Created by Florian Lehmann on 05/04/2018.
//

#include <check.h>
#include <stdlib.h>
#include "../src/ParallelParser.h"

START_TEST(shouldReadFirstLine)
{
    unsigned int lineSize;
    const char * obtained = readFirstLine("../../resources/test1", &lineSize);
    const char expected[] = "1 5 -2 10\n";
    ck_assert_mem_eq(obtained, expected, lineSize * sizeof(char));
}
END_TEST

START_TEST(shouldExtractIntegerFromLine)
    {
        unsigned int lineSize = 11;

        char line [] = "1 5 -2 10\n";
        int * obtained = (int *) malloc(lineSize* sizeof(int));
        int nbElements = extractIntegerFromFile(obtained, line);
        int expected[] = {1, 5, -2, 10};
        ck_assert_int_eq(nbElements, 4);
        ck_assert_mem_eq(obtained, expected, nbElements * sizeof(int));
    }
END_TEST

Suite * parallelParser_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("ParallelParser");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, shouldReadFirstLine);
    tcase_add_test(tc_core, shouldExtractIntegerFromLine);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = parallelParser_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
