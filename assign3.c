#include <stdio.h>
#include <sys/types.h>

static inline void
__cpuid(unsigned int *eax, unsigned int *ebx, unsigned int *ecx,
unsigned int *edx)
{
asm volatile("cpuid"
: "=a" (*eax),
"=b" (*ebx),
"=c" (*ecx),
"=d" (*edx)
: "0" (*eax), "1" (*ebx), "2" (*ecx), "3" (*edx));
}

int
main(int argc, char **argv)
{
unsigned int eax, ebx, ecx, edx;
unsigned long long time;

eax = 0x4FFFFFFE;
__cpuid(&eax, &ebx, &ecx, &edx);
time = (unsigned long long) ebx << 32 | ecx;
printf("######################\n");
printf("CPUID(0x4FFFFFFE), EXIT=%u, TOTAL EXIT CYCLES=%llu\n", eax, time);
}
