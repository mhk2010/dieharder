dieharder is a fairly involved random number/uniform deviate generator
tester.  It can either test any of its many prebuilt and linked
generators (basically all of those in the Gnu Scientific Library plus
others I've added) or a potentially random dataset in a file.  With file
input, it can manage either a variety of ascii-formatted input or a raw
binary bitstring.  It is thus suitable for use in testing both software
RNG's and hardware RNG's.

dieharder does all of its work with a standalone, extensible library, libdieharder.
Its tests can therefore be integrated into other programs, subject to
the requirements of the GPL (NOT, note, the LGPL as it uses the GSL
which is full GSL, viral).

dieharder encapsulates (or will eventually encapsulate) basically all
the random number tests I have been able to find -- George Marsaglia's
'diehard' battery of tests, STS (v1.5) from NIST FIPS, Knuth's tests,
and more.  Check in the man page or /usr/share documentation for a
complete list of the tests and references where possible.  It is
intended to be the 'swiss army knife of random number testers', or 'the
last suite of random number testers you'll ever wear'.