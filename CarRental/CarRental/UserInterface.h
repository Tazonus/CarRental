#pragma once
#include "Interface.h"

class UserInterface :
    public Interface
{
public:
    /// <summary>
    /// Runs a user interface
    /// </summary>
    /// <returns>
    ///     <para> 1 -> logged to admin panel </para>
    ///     <para> 2 -> logoff from admin panel </para>
    ///     <para> 0 -> exit program</para>
    /// </returns>
    int Run();
};

