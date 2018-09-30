#
# Be sure to run `pod lib lint ADMobGenSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
    s.name             = 'ADMobGenSDK'
    s.version          = '1.2.0'
    s.summary          = 'A short description of ADMobGenSDK.'
    
    # This description is used to generate tags and improve search results.
    #   * Think: What does it do? Why did you write it? What is the focus?
    #   * Try to keep it short, snappy and to the point.
    #   * Write the description between the DESC delimiters below.
    #   * Finally, don't worry about the indent, CocoaPods strips it!
    
    s.description      = <<-DESC
    TODO: Add long description of the pod here.
    DESC
    
    s.homepage         = 'http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDK'
    # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { '1594717129@qq.com' => '1594717129@qq.com' }
    s.source           = { :git => 'http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDK.git', :tag => s.version.to_s }
    # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
    
    s.ios.deployment_target = '8.0'
    
    s.vendored_frameworks = 'ADMobGenSDK/Classes/*.framework'
    
    s.dependency 'ADMobGenAdapter'
    s.dependency 'ADMobGenNetwork'
    
    # s.resource_bundles = {
    #   'ADMobGenSDK' => ['ADMobGenSDK/Assets/*.png']
    # }
    
    # s.public_header_files = 'Pod/Classes/**/*.h'
    # s.frameworks = 'UIKit', 'MapKit'
    # s.dependency 'AFNetworking', '~> 2.3'
end

