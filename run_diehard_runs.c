/*
 *========================================================================
 * $Id: dieharder.c 127 2004-11-20 18:17:55Z rgb $
 *
 * See copyright in copyright.h and the accompanying file COPYING
 *========================================================================
 */

/*
 *========================================================================
 *  run_diehard_runs()
 *========================================================================
 */

#include "dieharder.h"

void run_diehard_runs()
{

 /*
  * Declare the results struct.
  */
 Test **diehard_runs_test;

 /*
  * First we create the test (to set some values displayed in test header
  * correctly).
  */
 diehard_runs_test = create_test(&diehard_runs_dtest,tsamples,psamples,&diehard_runs);

 /*
  * Set any GLOBAL data used by the test.
  */
 diehard_runs_rand_int = (uint *)malloc(diehard_runs_test[0]->tsamples*sizeof(uint));
   

 /*
  * Show the standard test header for this test.
  */
 show_test_header(&diehard_runs_dtest,diehard_runs_test);

 /*
  * This is where we can output any test-specific information.
  */

 /*
  * Set any GLOBAL data used by the test.  Then call the test itself
  * This fills in the results in the Test struct.
  */
 std_test(&diehard_runs_dtest,diehard_runs_test);

 /*
  * This almost certainly belongs in the show_test_results section,
  * possibly with additional conditionals rejecting test results involving
  * rewinds, period.
  */
 if(strncmp("file_input",gsl_rng_name(rng),10) == 0){
   printf("# %u rands were used in this test\n",file_input_get_rtot(rng));
   printf("# The file %s was rewound %u times\n",gsl_rng_name(rng),file_input_get_rewind_cnt(rng));
 }

 /*
  * Show standard test results, for all statistics generated by a single run.
  */
 show_test_results(&diehard_runs_dtest,diehard_runs_test);

 /*
  * Free any GLOBAL data used by the test.
  */
 free(diehard_runs_rand_int);

}
