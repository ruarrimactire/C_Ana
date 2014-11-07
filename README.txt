C
http://www.microsoft.com/es-es/download/confirmation.aspx?id=43733
http://www.cprogramming.com/tutorial/unicode.html
https://forums.freebsd.org/threads/where-is-u_int32_t-defined.10028/
http://www.opensource.apple.com/source/xnu/xnu-1456.1.26/EXTERNAL_HEADERS/stdint.h
http://stackoverflow.com/questions/5163835/what-is-u-int32-t
https://www.google.es/search?q=%23define+u_int32_t&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a&channel=fflb&gfe_rd=cr&ei=qXBaVLmuMeXH8gflj4CoBg#rls=org.mozilla:en-US:official&channel=fflb&q=%27typedef.*u_int32_t%3B%27
http://www.fox-toolkit.org/
http://stackoverflow.com/questions/7959573/declaring-variables-inside-loops-good-practice-or-bad-practice-2-parter
https://github.com/VioletGiraffe/cppcheck-vs-addin/releases
http://cppcheck.sourceforge.net/
http://stackoverflow.com/questions/2630082/fatal-error-c1083-cannot-open-include-file
http://www.yolinux.com/TUTORIALS/GDB-Commands.html
http://stackoverflow.com/questions/6121094/how-do-i-run-a-program-with-commandline-args-using-gdb-within-a-bash-script
https://forums.netbeans.org/post-61565.html


http://www.cplusplus.com/reference/cwctype/towupper/
	/* towupper example */
	#include <stdio.h>
	#include <wctype.h>
	int main ()
	{
	  int i=0;
	  wchar_t str[] = L"Test String.\n";
	  wchar_t c;
	  while (str[i])
	  {
		c = str[i];
		putwchar (towupper(c));
		i++;
	  }
	  return 0;
	}

