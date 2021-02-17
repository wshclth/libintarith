Interval Arithmetic
A simple floating point library that performs interval arithmetic.
See https://en.wikipedia.org/wiki/Interval_arithmetic for more info.

`make all` builds the libintarith.so
`make tests` builds the tests executable
`make install` installs to /usr/lib/
`make remove` deletes install from /usr/lib

====================================================================

Successfull test output

[working] computing pie to 500000 iterations ...
[result] +3.1415906535896920 ∈ [+3.1415906534787763, +3.1415906537008205] err = 2.220442e-10
[pass] 3.141591 <= 3.141591 <= 3.141591, fpe = 0.0000000002220442

[working] normalizing vector
[result] +0.9999999999999991 ∈ [+0.9999999999999808, +1.0000000000000180] err = 3.719247e-14
[pass] norm == 1 with precision >= 1e-14

[working] computing sqrt(2) to machine precision
[result] +1.4142135623730949 ∈ [+1.4142135623730949, +1.4142135623730951] err = 2.220446e-16
[pass] 1.414214 is sqrt(2) computed to machine precision

=====================================================================

Currently supported operations, +,-,/,*,sqrt. Currently / where split sets
between (-inf, a] U [b, +inf) where a < 0 < b are not supported.
