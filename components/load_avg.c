/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <stdlib.h>

#include "../util.h"

const char *
load_avg(void)
{
	double avgs[3];

	if (getloadavg(avgs, 3) < 0) {
		warn("getloadavg: Failed to obtain load average");
		return NULL;
	}

	if (avgs[0] < 1) {
    double i = avgs[0] * 100;
    return bprintf(".%02.0f", i);
	}

	return bprintf("%.2f", avgs[0]);
}
