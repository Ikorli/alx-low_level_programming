#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

void print_header_info(Elf64_Ehdr *header);
int main(int argc, char **argv)
{
if (argc != 2)
{
fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
return (EXIT_FAILURE);
}

FILE *file = fopen(argv[1], "rb");
if (!file)
{
fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
return (EXIT_FAILURE);
}

Elf64_Ehdr header;
if (fread(&header, sizeof(header), 1, file) != 1)
{
fprintf(stderr, "Error: could not read ELF header from file '%s'\n", argv[1]);
return (EXIT_FAILURE);
}

print_header_info(&header);

fclose(file);
return (EXIT_SUCCESS);
}
void print_header_info(Elf64_Ehdr *header)
{
printf("ELF Header:\n");

printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");

printf("Class");
switch (header->e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
break;
}

printf("Data");
switch (header->e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
break;
}
printf("  Version:%d", header->e_ident[EI_VERSION]);
switch (header->e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}

printf("OS/ABI");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default
