/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Download a file.
void downloadFile(int fileId, int year, int month)
{
	string tempYear = intToString(year, false);
	string tempMonth = intToString(month, true);
	string tempFileId = intToString(fileId, true);
	string tempUrl = stringInit(CMD_MAX + 1);

	tempUrl = stringCopy(tempUrl, "bitsadmin /transfer DownloadJob /download ", NULL);

	tempUrl = stringConcat(tempUrl,
		"http://www.weather.gov.sg/files/dailydata/DAILYDATA_S", tempFileId, "_", tempYear, tempMonth, ".csv ",
		"\"", WORKING_DIR, "\\Downloads\\DAILYDATA_S", tempFileId, "_", tempYear, tempMonth, ".csv\"",
		NULL);

	stringDispose(tempYear);
	stringDispose(tempMonth);
	stringDispose(tempFileId);

	system(tempUrl);

	stringDispose(tempUrl);
}

// A function to show menu D4.3.
void showMenuD4_3(void)
{
	int id;
	int year = 2016;
	int month = 1;
	int currentImportIndex = 1;

	FILE* file;
	char filename[CMD_MAX + 1];

	string tempCategoryName;
	string tempLineText = stringInit(CMD_MAX + 1);
	string tempGetSplit;

	int tempYear;
	int tempMonth;
	int tempDay;
	float tempValue;

	bool isCategoryAdded = false;
	bool isFirstLine = false;

	printHeader("D4.3. Rainfall database manager - Sync database with internet server.");

	if (mkdir("Downloads") == 0)
		printf("> Created a folder at: %s%s\n", WORKING_DIR, "\\Downloads");
	else
		puts("> Directory existed, skipping.");

	/*
		List of File ID
		Paya Lebar - 06
		Macritchie Reservoir - 07
		Lower Peirce Reservoir - 08
		Choa Chu Kang (West) - 11
		Tengah - 23
		Changi - 24
		Seletar - 25
		Pasir Ris (West) - 29
		Kampong Bahru - 31
		Jurong Pier - 33
		Ulu Pandan - 35
		Serangoon - 36
		Jurong (East) - 39
		Mandai - 40
		Tai Seng - 43
		Jurong (West) - 44
		Upper Thomson - 46
		Clementi - 50
		Buangkok - 55
		Sentosa Island - 60
		Chai Chee - 61
		Boon Lay (West) - 63
		Bukit Panjang - 64
		Kranji Reservoir - 66
		Upper Peirce Reservoir - 69
		Kent Ridge - 71
		Tanjong Pagar - 72
		Queenstown - 77
		Tanjong Katong - 78
		Somerset (Road) - 79
		Sembawang - 80
		Punggol - 81
		Tuas West - 82
		Simei - 84
		Boon Lay (East) - 86
		Toa Payoh - 88
		Tuas - 89
		Bukit Timah - 90
		Yishun - 91
		Buona Vista - 92
		Pasir Ris (Central) - 94
		Jurong (North) - 101
		Semakau Island - 102
		Admiralty - 104
		Admiralty West - 105
		Pulau Ubin - 106
		East Coast Parkway - 107
		Marina Barrage - 108
		Ang Mo Kio - 109
		Serangoon North - 110
		Newton - 111
		Lim Chu Kang - 112
		Marine Parade - 113
		Choa Chu Kang (Central) - 114
		Tuas South - 115
		Pasir Panjang - 116
		Jurong Island - 117
		Dhoby Ghaut - 118
		Nicoll Highway - 119
		Botanic Garden - 120
		Choa Chu Kang (South) - 121
		Khatib - 122
		Whampoa - 123
	*/

	for (id = 6; id < 124; id++)
	{
		if ((id >= 6 && id <= 8) || id == 11 || (id >= 23 && id <= 25) || id == 29 || id == 31 || id == 33 || id == 35 || id == 36 || id == 39 || id == 40 || id == 43 || id == 44 || id == 46 || id == 50 || id == 55 || id == 60 || id == 61 || id == 63 || id == 64 || id == 66 || id == 69 || id == 71 || id == 72 || (id >= 77 && id <= 82) || id == 84 || id == 86 || (id >= 88 && id <= 92) || id == 94 || id == 101 || id == 102 || (id >= 104 && id <= 123))
			downloadFile(id, year, month);
	}

	puts("> Download completed!");

	for (id = 6; id < 124; id++)
	{
		if ((id >= 6 && id <= 8) || id == 11 || (id >= 23 && id <= 25) || id == 29 || id == 31 || id == 33 || id == 35 || id == 36 || id == 39 || id == 40 || id == 43 || id == 44 || id == 46 || id == 50 || id == 55 || id == 60 || id == 61 || id == 63 || id == 64 || id == 66 || id == 69 || id == 71 || id == 72 || (id >= 77 && id <= 82) || id == 84 || id == 86 || (id >= 88 && id <= 92) || id == 94 || id == 101 || id == 102 || (id >= 104 && id <= 123))
		{
			printf("> Importing Data (%d / 63) %.2f%%\n", currentImportIndex, currentImportIndex / 63.0 * 100.0);

			// Get filename.
			stringCopy(filename, "Downloads\\DAILYDATA_S", intToString(id, true), "_", intToString(year, false), intToString(month, true), ".csv", NULL);

			// Open the file, give read permission.
			file = fopen(filename, "r");

			// Reset Variable
			isFirstLine = false;
			isCategoryAdded = false;

			if (file == NULL)
			{
				puts("> Unable to find the requested file. Skipping.");
				currentImportIndex++;
				continue;
			}
			else
			{
				do
				{
					tempLineText = fgets(tempLineText, INT_MAX, file);

					if (tempLineText == NULL)
						break;
					else
					{
						if (!isFirstLine)
						{
							isFirstLine = true;
							continue;
						}

						if (!isCategoryAdded)
						{
							tempCategoryName = stringGetSplit(tempLineText, 0, ',');
							rainfallCategoryListAdd(tempCategoryName);
							stringDispose(tempCategoryName);
							isCategoryAdded = true;
						}
						
						tempGetSplit = stringGetSplit(tempLineText, 1, ',');
						tempYear = stringToInt(tempGetSplit);
						stringDispose(tempGetSplit);

						tempGetSplit = stringGetSplit(tempLineText, 2, ',');
						tempMonth = stringToInt(tempGetSplit);
						stringDispose(tempGetSplit);

						tempGetSplit = stringGetSplit(tempLineText, 3, ',');
						tempDay = stringToInt(tempGetSplit);
						stringDispose(tempGetSplit);

						tempGetSplit = stringGetSplit(tempLineText, 4, ',');
						tempValue = stringToFloat(tempGetSplit);
						stringDispose(tempGetSplit);

						rainfallDayListSetItem(rainfallCategoryListCount() - 1, tempYear - START_YEAR, tempMonth - 1, tempDay - 1, tempValue);

						if (getDayCount(tempYear, tempMonth) == tempDay)
							break;
					}
				} while (tempLineText != NULL);

				currentImportIndex++;
				fclose(file);
			}
		}
	}

	puts("> Database imported!");
	system("pause");
}