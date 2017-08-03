Pod::Spec.new do |s|
  s.name             = 'ZTuple'
  s.version          = '1.0.0'
  s.summary          = 'ZTuple.'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/WilliamZang/ZTuple'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'WilliamZang' => 'chengwei.zang.1985@gmail.com' }
  s.source           = { :git => 'https://github.com/WilliamZang/ZTuple.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  s.osx.deployment_target = '10.8'

  s.source_files = 'ZTuple/**/*.{m,h}'

  s.public_header_files = 'ZTuple/**/*.h'
  
  s.module_map = 'ZTuple/ZTuple.modulemap'
  
  s.frameworks = 'Foundation'
  
  s.dependency 'libextobjc', '~> 0.4.1'
end
