#!/bin/sh

# run test
PAAT=`basename $1`;
awk -v PAT="$PAAT" -f scripts/genlink.awk $1.data > $1.out;

#check test
if ! diff -q $1.out $1.result >/dev/null; then
	printf "FAILED\n";
	exit 1;
fi

#remove workout only if it is OK
rm -f $1.out

printf "OK\n";
exit 0  