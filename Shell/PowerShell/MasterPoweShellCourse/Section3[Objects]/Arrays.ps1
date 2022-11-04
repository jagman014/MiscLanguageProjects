# @() to define array
$strComputers = @("Server1", "Server2", "Server3")

Write-Output $strComputers
# zero indexed
Write-Output $strComputers[0]

$strComputers[2] = "Server4"
Write-Output $strComputers

$strComputers | Get-Member
Write-Output $strComputers.Length

$strComputers2 = @("Server5", "server6")

$allComputers = $strComputers + $strComputers2
Write-Output $allComputers

$allComputers | ForEach-Object {$_ + " - " + $_.Length}
