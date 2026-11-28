
$watcher = New-Object System.IO.FileSystemWatcher
$watcher.Path = $PSScriptRoot
$watcher.Filter = "*.*"
$watcher.IncludeSubdirectories = $true
$watcher.EnableRaisingEvents = $true

$extensions = @(".cpp", ".h")

Write-Host "Watching C++ files... Press Ctrl+C to stop."

while ($true) {
    $result = $watcher.WaitForChanged("Changed")

    $extension = [System.IO.Path]::GetExtension($result.Name)

    if ($extensions -contains $extension) {
        Start-Sleep -Milliseconds 700

        Write-Host "`nChange detected: $($result.Name)"

        $runningGame = Get-Process game -ErrorAction SilentlyContinue
        if ($runningGame) {
            $runningGame | Stop-Process -Force
        }

        & "$PSScriptRoot/build.ps1"
    }
}
