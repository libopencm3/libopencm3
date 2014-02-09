BEGIN {
	STR = "   [%-6s] %6d bytes (%3.2f %% full) %s\n";
	ROM_MATCH = "^"ROM_OFF"$";
	RAM_MATCH = "^"RAM_OFF"$";
	CCM_MATCH = "^"CCM_OFF"$";
	EEP_MATCH = "^"EEP_OFF"$";
}
function percent(a,b) { return strtonum(a) * 100 / (strtonum(b) * 1024); }
($1 ~ /^LOAD$/ && $3 ~ ROM_MATCH) { printf STR, "FLASH", strtonum($6), percent($6,ROM), "[.text + .data]"; }
($1 ~ /^LOAD$/ && $3 ~ RAM_MATCH) { printf STR, "RAM", strtonum($6), percent($6,RAM), "[.data + .bss]"; }
($1 ~ /^LOAD$/ && $3 ~ CCM_MATCH) { printf STR, "CCM", strtonum($6), percent($6,CCM), "[.ccmram]"; }
($1 ~ /^LOAD$/ && $3 ~ EEP_MATCH) { printf STR, "EEPROM", strtonum($6), percent($6,EEP), "[.eeprom]"; }
