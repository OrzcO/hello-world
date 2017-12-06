#include <stdio.h>
#include <unistd.h>


// fujincheng xian zhixing wan yi bian zhu chengxu , ran hou rang zi chengxu 
// an zhao xiangtong de celue zhixing ,ji zichegxu zuo wei fujincheng zhixing 
// suoyi  xianshi abc
main(){
	int p1 , p2;
	while((p1=fork())==-1);
	if(p1 == 0)
		putchar('b');
	else
	{
		while((p2=fork())==-1);
		if(p2 == 0)
			putchar('c');
		else
			putchar('a');
	}
}
