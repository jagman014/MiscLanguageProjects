$files = Get-ChildItem

# change object output format
$files | Format-Wide

# display only certain properties
$files | Format-Wide -Property Length

$files | Format-List

$files | Format-List -Property Name, Length

$files | Format-Table

Get-Process | Format-Table

Get-Process | Format-Table -Property Path, Name, Id, Company -AutoSize

# can sort and group
Get-Process | Sort-Object -Property Company | Format-Table -Property Path, Name, Id -GroupBy Company
