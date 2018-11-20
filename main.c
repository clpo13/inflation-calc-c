// Simple command-line program to print the rate of inflation
// Copyright (c) 2018 Cody Logan, released under the MIT license
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 80  // buffer size constant

int main(int argc, char **argv) {
    char filename[] = "cpi.csv";  // file to parse
    char line[BSIZE];             // char array to hold each line
    long year;                    // long integer representation of year
    double cpi;                   // consumer price index

    // open the file for reading
    FILE *stream = fopen(filename, "r");
    if (stream == NULL) {
        printf("Cannot open %s\n", filename);
        exit(1);
    }

    // read filestream line-by-line
    while (fgets(line, 1024, stream)) {
        char *field;  // holds individual CSV fields
        char *ptr;    // holds unconverted portion of the line (if any)

        // first field is the year (delimited by a comma)
        field = strtok(line, ",");
        year = strtol(field, &ptr, 10);

        // second field is the CPI value (delimited by a comma or newline)
        field = strtok(NULL, ",\n");
        cpi = strtod(field, &ptr);

        // Discard first line (header)
        // This works because the header line is [Year, CPI], so the conversions
        // above with strtol() and strtod() result in year and cpi being 0 and
        // 0.000000 respectively. The unconverted portion of the line is put in
        // ptr, which is first "Year" then, at this point, "CPI".
        if (year == 0 && cpi == 0 && strcmp(ptr, "CPI") == 0) {
            continue;
        }

        // print year and CPI (truncated to three decimal places)
        printf("CPI for %ld is %.3f\n", year, cpi);
    }

    // close the filestream
    fclose(stream);
}