# Inflation Calculator

A simple command-line tool to find the difference in purchasing power of the US
dollar, as well as the cumulative percent of inflation, between two years.

The included [cpi.csv](cpi.csv) file contains annual Consumer Price Indices from
1913 to 2016, sourced from the United States
[Bureau of Labor Statistics](http://www.bls.gov/cpi/) website.

## Requirements

* A C compiler (gcc, clang, MSVC, etc.)
* CMake

## Compile and run

In the top source directory, run:

```bash
mkdir build && cd build
cmake ..
make
```

Then run `./inflation-calc`.

## Caveats

Make sure `cpi.csv` is in the same directory, or you'll get an error. CMake will
automatically copy the file to the build directory, but if you move the built
binary, the CSV needs to go with it.

## Purpose

For now, the program just reads the CSV and spits formatted data out, but the
idea is to be able to compare the purchasing power of a given amount of USD for
two different years. For example, `inflation-calc --amount 1.00 1913 2016` should
return `$24.24`. Optionally, the cumulative rate of inflation would be returned
if specified with a command-line flag.

## TODO

* [ ] Accept user input to compare different years
* [ ] Include CPI data in a more portable way (instead of copying the CSV)
* [ ] Pull data directly from [BLS](https://www.bls.gov/cpi/) via their API

## License

This code is free to use, modify, and distribute according to the terms of the
MIT License, the text of which is available in [LICENSE](LICENSE).
