Pod::Spec.new do |spec|
  spec.name = 'NOCLog'
  spec.version = '0.1.4'
  spec.summary = 'A debug log library for use in Objective-C projects.'

  spec.homepage = 'https://github.com/a-snail/NOCLog'
  spec.license = { :type => 'MIT', :file => 'LICENSE' }
  spec.author = { 'Jaeo Bok' => 'snail.bok@gmail.com' }
  spec.social_media_url = 'https://twitter.com/NOCLog'
  
  spec.platforms = { :ios => '8.0' }
  spec.ios.deployment_target = '8.0'
  spec.requires_arc = true

  spec.source = { :git => 'https://github.com/a-snail/NOCLog.git', :tag => spec.version.to_s }
  spec.source_files = 'NOCLog/*.{h,m}'
end
