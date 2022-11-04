# parameters (script args)
param([String]$dir="C:\")

# functions
function Get-DirInfo($dir) {
    $results = Get-ChildItem $dir -Recurse | Measure-Object -Property Length -Sum
    return "$([System.Math]::Round(($results).Sum / 1MB, 2)) MB"
}

# main
Get-DirInfo $dir
