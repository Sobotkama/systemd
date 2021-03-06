/* SPDX-License-Identifier: LGPL-2.1+ */

#include <net/if_arp.h>
#include <string.h>

#include "macro.h"
#include "string-util.h"
#include "util.h"

_unused_ \
static const struct arphrd_name* lookup_arphrd(register const char *str, register GPERF_LEN_TYPE len);

#include "arphrd-from-name.h"
#include "arphrd-list.h"
#include "arphrd-to-name.h"

int main(int argc, const char *argv[]) {

        unsigned int i;

        for (i = 1; i < ELEMENTSOF(arphrd_names); i++) {
                if (arphrd_names[i]) {
                        assert_se(streq(arphrd_to_name(i), arphrd_names[i]));
                        assert_se(arphrd_from_name(arphrd_names[i]) == (int) i);
                }
        }

        assert_se(arphrd_to_name(arphrd_max()) == NULL);
        assert_se(arphrd_to_name(0) == NULL);
        assert_se(arphrd_from_name("huddlduddl") == 0);
        assert_se(arphrd_from_name("") == 0);

        return 0;
}
