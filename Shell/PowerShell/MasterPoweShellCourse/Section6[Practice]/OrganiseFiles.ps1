# Parameters
param([String]$source=".\Source", [String]$destination=".\Destination")

# Functions
function Test-Folder([String]$path, [Switch]$Create) {
    $exists = Test-Path $path

    if (!$exists -and $Create) {
        mkdir $path | Out-Null

        $exists = Test-Path $path
    }

    return $exists
}

function Show-FolderStats([String]$path) {
    $files = Get-ChildItem $path -Recurse | Where-Object {!$_.PSIsContainer}
    $totals = $files | Measure-Object -Property Length -Sum
    $size = $([System.Math]::Round($totals.Sum / 1MB, 2))
    # use .NET DataTable
    $stats = New-Object System.Data.DataTable

    $stats.Columns.AddRange(("Path", "Count", "Size (MB)")) | Out-Null
    $stats.Rows.Add($path, $totals.Count, $size) | Out-Null

    return $stats
}

# main
$sourceExists = Test-Folder $source

if (!$sourceExists) {
    Write-Error "Source Directory $source Was Not Found"
    Exit
}

$destinationExists = Test-Folder $destination -Create

if (!$destinationExists) {
    Write-Error "Destination Directory $destination Was Not Found"
    Exit
}

$source = [System.Management.Automation.WildcardPattern]::Escape((Convert-Path $source))
$destination = [System.Management.Automation.WildcardPattern]::Escape((Convert-Path $destination))

$files = Get-ChildItem $source -Recurse | Where-Object {!$_.PSIsContainer}

ForEach ($file in $files) {
    $extension = $file.Extension.Replace(".", "")

    $extensionDestination = [System.Management.Automation.WildcardPattern]::Escape("$destination\$extension")

    $extensionDestinationExists = Test-Folder $extensionDestination -Create

    if (!$extensionDestinationExists) {
        Write-Error "Destination Directory $extensionDestination Can Not Be Created"
        Exit
    }

    $fileFullName = [System.Management.Automation.WildcardPattern]::Escape($file.FullName)

    Copy-Item $fileFullName $extensionDestination
}

$dirs = Get-ChildItem $destination | Where-Object {$_.PSIsContainer}

$allStats = @()

ForEach ($dir in $dirs) {
    $allStats += Show-FolderStats $dir.FullName
}

$allStats | Sort-Object 'Size MB' -Descending
