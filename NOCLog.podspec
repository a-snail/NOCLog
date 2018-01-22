Pod::Spec.new do |spec|
  spec.name = 'NOCLog'
  spec.version = '0.1.5'
  spec.summary = 'NOCLog is a very simple library that provides a debug logs in an Objective-C projects.'

  spec.homepage = 'https://github.com/a-snail/NOCLog'
  spec.license = { :type => 'MIT', :file => 'LICENSE' }
  spec.author = { 'Jaeo Bok' => 'snail.bok@gmail.com' }
  spec.social_media_url = 'https://twitter.com/snail_bok'

  spec.platforms = { :ios => '8.0' }
  spec.ios.deployment_target = '8.0'
  spec.requires_arc = true

  spec.source = { :git => 'https://github.com/a-snail/NOCLog.git', :tag => spec.version.to_s }
  spec.source_files = 'NOCLog/*.{h,m}'
end
