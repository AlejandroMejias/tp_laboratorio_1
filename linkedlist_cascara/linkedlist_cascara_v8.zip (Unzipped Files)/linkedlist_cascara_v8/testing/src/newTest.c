/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*INCLUDE LIBRARY TO TEST*/
#include "../../inc/LinkedList.h"


void newTestSetup(void)
{
	utest_print("Setup...\r\n");

}

void newTestCase01(void)
{
    LinkedList* lista = ll_newLinkedList();
    utest_assertNotNullMsg(lista,"\nExiste un error. El valor de retorno no puede ser NULL\n");
}



