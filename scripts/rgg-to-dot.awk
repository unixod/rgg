#!/usr/bin/env -S awk -f
#
# Convert output of rgg (expected on stdin) to DOT format (printed to stdout).
#
# Example:
#    $ rgg 10 3 | rgg-to-dot.awk
#

BEGIN {
    print "digraph {"
}

{
    printf $1
    if(NF > 1) {
        printf " -> {" $2
        for (i=3; i < NF; ++i) {
            printf(";%s", $i)
        }
        printf "}"
    }
    print ""
}

END {
    print "}"
}
