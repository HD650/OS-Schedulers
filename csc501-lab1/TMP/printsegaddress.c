#include <stdio.h>

extern char etext, edata, end; /* The symbols must have some type,
                                   or "gcc -Wall" complains */

void printsegaddress()
{
printf("Current: etext[0x%08X]=0x%08X, edata[0x%08X]=0x%08X, ebs[0x%08X]=0x%08X\n",&etext-1,*(&etext-1),&edata-1, *(&edata-1),&end-1,*(&end-1));
printf("Preceding: etext[0x%08X]=0x%08X, edata[0x%08X]=0x%08X, ebs[0x%08X]=0x%08X\n",&etext-2,*(&etext-2),&edata-2, *(&edata-2),&end-2,*(&end-2));
printf("After: etext[0x%08X]=0x%08X, edata[0x%08X]=0x%08X, ebs[0x%08X]=0x%08X\n",&etext,*(&etext),&edata, *(&edata),&end,*(&end));   

	/*printf("Last Address of:\n");
    printf("    Text segment (etext)      %x\n", &etext-1);
    printf("    Data segment (edata)  %x\n", &edata-1);
    printf("    BSS segment (end)  %x\n", &end-1);

    printf("Contents of address preceding the last address of :\n");
    printf("    Text segment (etext)      %x\n", *(&etext-2));
    printf("    Data segment (edata)  %x\n", *(&edata-2));
    printf("    BSS segment (end)  %x\n", *(&end-2));

    printf("Contents of address after the last address of :\n");
    printf("    Text segment (etext)      %x\n", *(&etext));
    printf("    Data segment (edata)  %x\n", *(&edata));
    printf("    BSS segment (end)  %x\n", *(&end));
*/
   
}
