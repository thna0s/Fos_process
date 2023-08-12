#include<BootLoader.h>


EFI_STATUS
EFIAPI 
UefiMain(EFI_HANDLE ImageHandle,EFI_SYSTEM_TABLE *SystemTable)
{
    
    EFI_STATUS Status=EFI_SUCCESS;
    Status=Draw_FOs_GRAPHICS(ImageHandle);

    Print(L"hell FOS\n");
    while(1)
    {
        
    }
    return Status;
}

