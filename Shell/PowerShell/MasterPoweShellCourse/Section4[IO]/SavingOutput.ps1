# write file
Get-Process | Out-File .\Processes.txt

# convert format
Get-Process | ConvertTo-Html | Out-File .\Processes.html

# invoke default program to open file
Invoke-Expression .\Processes.html

# specific export
Get-Process | Export-Csv .\Processes.csv

Invoke-Expression .\Processes.csv
