# This program converts chip name to the series of definitions for make of
# automatic linker script.
#
# Copyright (C) 2013 Frantisek Burian <Bufran@seznam.cz>
# Copyright (C) 2013 Werner Almesberger <wpwrak>
#

BEGIN {
	PAT = tolower(PAT);
}
!/^#/{
	tmp = "^"$1"$";
	gsub(/?/, ".", tmp);
	gsub(/*/, ".*", tmp);
	gsub(/+/, ".+", tmp);
	tolower(tmp);

	if (PAT ~ tmp) {
		if ($2 != "+")
			PAT=$2;
		$1="";
		$2="";
		for (i = 3; i <= NF; i = i + 1)
			$i = "-D"$i;
		print;
		if (PAT=="END") exit;
	}
}
