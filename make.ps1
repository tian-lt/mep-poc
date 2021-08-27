[CmdletBinding()]
param (
    [string]
    $VcpkgRoot,

    [string]
    $SourceDir = ".",

    [string]
    $BuildDir = "build",

    [string]
    $CMakeGenerator = 'Visual Studio 16',

    [string]
    $VcpkgTriplet = 'x64-windows',

    [string]
    $BuildType = 'Default'
)

[System.Environment]::CurrentDirectory = (Get-Location)
$SourceDir = [System.IO.Path]::GetFullPath($SourceDir)
Write-Host "SourceDIR: $SourceDir"
$BuildDir = [System.IO.Path]::GetFullPath($BuildDir)
Write-Host "BuildDIR: $BuildDir"

#ensure BuildDir
New-Item -ItemType Directory -Force -Path $BuildDir | Out-Null

#ensure VcpkgRoot
if ([string]::IsNullOrEmpty($VcpkgRoot)) {
    try {
        $VcpkgRoot = Get-Content "$BuildDir\PGMAKE_VCPKG_ROOT.txt" -ErrorAction Stop
        if([string]::IsNullOrEmpty($VcpkgRoot)) {
            throw "var-VcpkgRoot not found"
        }
    }
    catch {
        Write-Host "Missing argument *VcpkgRoot*, try to use -VcpkgRoot '<path-to-vcpkg>'" -ForegroundColor Red
        return
    }
}
else {
    Set-Content -Path "$BuildDir\PGMAKE_VCPKG_ROOT.txt" $VcpkgRoot
}

#ensure BuildType
if($BuildType -eq 'Default'){
    try{
        $BuildType = Get-Content "$BuildDir\PGMAKE_BUILD_TYPE.txt" -ErrorAction Stop
        if ([string]::IsNullOrEmpty($BuildType)) {
            $BuildType = 'Debug'
        }
    }
    catch{
        $BuildType = 'Debug'
    }
}
else{
    Set-Content -Path "$BuildDir\PGMAKE_BUILD_TYPE.txt" $BuildType
}

Write-Host "BuildType: $BuildType"

#run cmake
cmake -S "$SourceDir" -B "$BuildDir" -G "$CMakeGenerator" -DCMAKE_TOOLCHAIN_FILE="$VcpkgRoot/scripts/buildsystems/vcpkg.cmake" -DVCPKG_TARGET_TRIPLET="$VcpkgTriplet" -DCMAKE_BUILD_TYPE="$BuildType" -Wno-dev
