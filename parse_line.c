#include "monty.h"

/**
 * parse_line - parses through a line and returns the proper instruction
 * @line: the line
 *
 * Return: a pointer to the proper instruction
 */
instruction_t *parse_line(char *line)
{
	char *opcode;
	int i;
	instruction_t *instruction;
	instruction_t instructions[] = {
	    {"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub}, {"div", divide}, {"mul", multiply}, {"mod", moddy}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr}, {"stack", stack}, {"queue", queue}};

	opcode = get_opcode(line);
	instruction = malloc(sizeof(*instruction));
	if (instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	instruction->f = NULL;
	/* opcode selection */
	if (opcode)
	{
		for (i = 0; i < 17; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instruction->opcode = opcode;
				instruction->f = instructions[i].f;
				return (instruction);
			}
		}
	}
	instruction->opcode = opcode;
	return (instruction);
}
