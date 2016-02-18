# This awk program generates parameters for the linker script generator feature.
#
# See ld/README file for more info.
#

# This file is part of the libopencm3 project.
# 
# Copyright (C) 2013 Frantisek Burian <Bufran@seznam.cz>
# Copyright (C) 2013 Werner Almesberger <wpwrak>
# 
# This library is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with this library. If not, see <http://www.gnu.org/licenses/>.

BEGIN {
	PAT = tolower(PAT);
	family = PAT;
}
!/^#/{
	#remove cr on windows
	gsub(/\r$/,"");

	tmp = "^"$1"$";
	gsub(/\?/, ".", tmp);
	gsub(/\*/, ".*", tmp);
	gsub(/\+/, ".+", tmp);
	tolower(tmp);

	if (PAT ~ tmp) {
		if ("CPPFLAGS" == MODE)
			printf "-D%s ",toupper(PAT);
		if ($2 != "+")
			PAT=$2;
                for (i = 3; i <= NF; i = i + 1) {
			if ($i ~ /^CPU=/) {
				if ("CPU" == MODE){
					sub(/[^=]*=/,"",$i);
					printf "%s",$i;
					exit;
				}
			}
			else if ($i ~ /^FPU=/) {
				if ("FPU" == MODE){
					sub(/[^=]*=/,"",$i);
					printf "%s",$i;
					exit;
				}
			}
			else if ($i ~ /[[:upper:]]*=/) {
				if ("DEFS" == MODE)
					printf "-D_%s ",$i;
			}
		}
		if (PAT=="END"){
			if ("FAMILY" == MODE)
				printf "%s",family;
			else if ("SUBFAMILY" == MODE)
				printf "%s",subfamily;
			exit;
		}
		else{
			subfamily = family;
			family = PAT;
	                if("DEFS" == MODE)
				printf "-D%s ",toupper(PAT);
		}
	}
}
