#!/bin/sh

# This script is intended to test the python program genlink.py for the linker 
# script generator feature.
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

# run test
DEVICE=`basename $1`;
(scripts/genlink.py $1.data $DEVICE CPPFLAGS; echo) > $1.out
(scripts/genlink.py $1.data $DEVICE DEFS; echo) >> $1.out
(scripts/genlink.py $1.data $DEVICE FAMILY; echo) >> $1.out
(scripts/genlink.py $1.data $DEVICE SUBFAMILY; echo) >> $1.out
(scripts/genlink.py $1.data $DEVICE CPU; echo) >> $1.out
(scripts/genlink.py $1.data $DEVICE FPU; echo) >> $1.out

#check test
if ! diff -q $1.out $1.result >/dev/null; then
	exit 1;
fi

#remove workout only if it is OK
rm -f $1.out

exit 0
