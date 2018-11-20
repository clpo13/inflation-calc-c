// Simple command-line program to print the rate of inflation
// Copyright (c) 2018 Cody Logan, released under the MIT license
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 80  // buffer size constant

// parse lines from a CSV file
// from <https://stackoverflow.com/questions/12911299/read-csv-file-in-c/12911465#12911465>
const char *getField(char *line, int num) {
    char *token;
    for (token = strtok(line, ","); token && *token; token = strtok(NULL, ",\n")) {
        if (!--num) {
            return token;
        }
    }
    return NULL;
}

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
        char *ptr;  // pointer to hold unconverted portion of the line
        year = strtol(getField(strdup(line), 1), &ptr, 10);
        cpi = strtod(getField(strdup(line), 2), &ptr);

        // Discard first line (header)
        // This works because the header line is [Year, CPI], so the conversions
        // above with strtol() and strtod() result in year and cpi being 0 and
        // 0.000000 respectively. The unconverted portion of the line is put in
        // ptr, which is first "Year" then, at this point, "CPI".
        if (year == 0 && cpi == 0 && strcmp(ptr, "CPI") == 0) {
            continue;
        }

        printf("CPI for %ld is %.3f\n", year, cpi);
    }

    // close the file
    fclose(stream);
}