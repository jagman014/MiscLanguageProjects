function Get-DirInfo($dir) {
    $results = Get-ChildItem $dir -Recurse | Measure-Object -Property Length -Sum
    # invoke .NET functions using [namespace]::<function>
    return "$([System.Math]::Round(($results).Sum / 1MB, 2)) MB"
}

Get-DirInfo ..\
