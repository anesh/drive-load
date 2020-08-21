#include "stdafx.h"
#include "serviceTools.h"

int createService(char* serviceName, char* executablePath, bool relative)
{
	char pathBuffer[200];

	if(relative)
	{
		GetCurrentDirectory(200, pathBuffer);
		strcat(pathBuffer, "\\");
	}

	strcat(pathBuffer, executablePath);

	printf("Creating service %s ", serviceName);

	SC_HANDLE sh = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);

	if(sh == INVALID_HANDLE_VALUE)
	{
		printf("Error opening handle to Service Manager.\n");
		return -1;
	}

	SC_HANDLE hService = CreateService(sh, serviceName, serviceName, 
										SERVICE_ALL_ACCESS, 
										SERVICE_KERNEL_DRIVER,
										SERVICE_DEMAND_START,
										SERVICE_ERROR_NORMAL,
										pathBuffer,
										0, 0, 0, 0, 0);
	CloseServiceHandle(sh);

	if(hService == 0)
	{
		printf("Error creating service.\n");
		printf("CreateService failed (%d)\n", GetLastError());
		return -1;
	}									

	printf("Service has been created under the display name of %s\n", serviceName);
						
	CloseServiceHandle(hService);

	return 1;
}

int startService(char* serviceName)
{
	SC_HANDLE hService;
	SC_HANDLE sh = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);
	

	if(!sh)
	{
		printf("Error opening service handler handle\n");
		return -1;
	}


	hService = OpenService(sh, serviceName, SERVICE_ALL_ACCESS);
	CloseServiceHandle(sh);

	if(!hService)
	{
		printf("Error opening service handle\n");
		return -1;
	}



	if(StartService(hService, 0, 0) != 0)
		printf("Service started.\n");
	else
	{
		unsigned long eCode = GetLastError();
		printf("Error starting service.(%d)\n", eCode);

		CloseServiceHandle(hService);
		return -1;
	}
	CloseServiceHandle(hService);

	return 1;
}

int stopService(char* serviceName)
{
	SC_HANDLE hService;
	SC_HANDLE sh = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);
	

	if(!sh)
	{
		printf("Error opening service handler handle\n");
		return -1;
	}


	hService = OpenService(sh, serviceName, SERVICE_ALL_ACCESS);
	CloseServiceHandle(sh);

	if(!hService)
	{
		printf("Error opening service handle\n");
		return -1;
	}


	SERVICE_STATUS srvStatus;
	if(ControlService(hService, SERVICE_CONTROL_STOP, &srvStatus) != 0)
		printf("Service stopped.\n");
	else
	{
		printf("Error stopping service.\n");
		CloseServiceHandle(hService);
		return -1;
	}

	CloseServiceHandle(hService);
	return 1;
}

int deleteService(char* serviceName)
{
	SC_HANDLE hService;
	SC_HANDLE sh = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);
	
	if(!sh)
	{
		printf("Error opening service handler handle\n");
		return -1;
	}


	hService = OpenService(sh, serviceName, SERVICE_ALL_ACCESS);

	CloseServiceHandle(sh);

	if(!hService)
	{
		printf("Error opening service handle\n");
		return -1;
	}



	if(DeleteService(hService) != 0)
		printf("Service deleted.\n");
	else
	{
		printf("Error deleting service.\n");
		CloseServiceHandle(hService);
		return -1;
	}

	CloseServiceHandle(hService);
}