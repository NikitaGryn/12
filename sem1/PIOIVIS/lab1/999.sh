#! /bin/bash
ps -eo fname,vsz | awk "{ if ($2 >= $1 && $2 <= $2) print $1,$2 }" | sort > processes.txt