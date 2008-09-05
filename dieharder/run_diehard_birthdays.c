/*
 *========================================================================
 * $Id: dieharder.c 127 2004-11-20 18:17:55Z rgb $
 *
 * See copyright in copyright.h and the accompanying file COPYING
 *========================================================================
 */

/*
 *========================================================================
 *  run_diehard_birthdays()
 *========================================================================
 */

#include "dieharder.h"

void run_diehard_birthdays()
{


 /*
  * Declare the results struct.
  */
 Test **diehard_birthdays_test;

 /*
  * First we create the test (to set some values displayed in test header
  * correctly).  Note that I think we must then DESTROY THE TEST ON EXIT!
  */
 diehard_birthdays_test = create_test(&diehard_birthdays_dtest,tsamples,psamples,&diehard_birthdays);
 fflush(stdout);

 /*
  * Set any GLOBAL data used by the test.  From Marsaglia, nms should just
  * be "512", but this CAN be varied and all his formulae still work.
  * Similarly, nbits should be "24", but we can really make it anything we
  * want that's less than or equal to rmax_bits.
  *
  * Note that there exists an "improved birthdays" test that probably
  * results from having varied these parameters looking at sensitivity
  * in Marsaglia and Tsang.
  */
 if(x_user != 0.0) {
   diehard_birthdays_nms = (int)x_user;
 } else {
   diehard_birthdays_nms = 512;  /* default value */
 }
 if(y_user != 0.0) {
   diehard_birthdays_nbits = (int)y_user;
 } else {
   diehard_birthdays_nbits = 24;
 }
 /*
  * The ring of rand uints
  */
 diehard_birthdays_rand_uint = (unsigned int *)malloc(diehard_birthdays_nms*sizeof(unsigned int));


 /*
  * Show the standard test header for this test.
  */
 show_test_header(&diehard_birthdays_dtest,diehard_birthdays_test);
 if(diehard_birthdays_test[0]->tsamples > 1000){
   printf("#==================================================================\n");
   printf("# WARNING WARNING WARNING!  This test rarely requires more than\n");
   printf("#   -t 300 to make nearly any generator fail, and will take a\n");
   printf("#   very long time to run even there.  Consider restarting.\n");
   printf("#==================================================================\n");
   fflush(stdout);
 }

 /*
  * This is where we can output any test-specific information.
  */

 /*
  * Set any GLOBAL data used by the test.  Then call the test itself
  * This fills in the results in the Test struct.
  */
 std_test(&diehard_birthdays_dtest,diehard_birthdays_test);

 /*
  * This almost certainly belongs in the show_test_results section,
  * possibly with additional conditionals rejecting test results involving
  * rewinds, period.
  */
 if(strncmp("file_input",gsl_rng_name(rng),10) == 0){
   printf("# %u rands were used in this test\n",file_input_get_rtot(rng));
   printf("# The file %s was rewound %u times\n",gsl_rng_name(rng),file_input_get_rewind_cnt(rng));
   fflush(stdout);
 }

 /*
  * Show standard test results, for all statistics generated by a single run.
  */
 show_test_results(&diehard_birthdays_dtest,diehard_birthdays_test);
 fflush(stdout);

 /*
  * Free any allocated globals before exit (or leak).
  */
 free(diehard_birthdays_rand_uint);

 /*
  * Destroy the test and free all dynamic memory it used.
  */
 destroy_test(&diehard_birthdays_dtest,diehard_birthdays_test);

}
